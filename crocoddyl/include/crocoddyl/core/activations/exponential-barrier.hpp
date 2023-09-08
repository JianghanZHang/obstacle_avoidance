///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2020, LAAS-CNRS, University of Edinburgh
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef CROCODDYL_CORE_ACTIVATIONS_EXP_BARRIER_HPP_
#define CROCODDYL_CORE_ACTIVATIONS_EXP_BARRIER_HPP_

#include "crocoddyl/core/activation-base.hpp"
#include "crocoddyl/core/fwd.hpp"
#include "crocoddyl/core/utils/exception.hpp"

namespace crocoddyl {

/*
    * @brief Quadratic-flat-exp activation
 */
template <typename _Scalar>
class ActivationModelExpBarrierTpl
    : public ActivationModelAbstractTpl<_Scalar> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef _Scalar Scalar;
  typedef MathBaseTpl<Scalar> MathBase;
  typedef ActivationModelAbstractTpl<Scalar> Base;
  typedef ActivationDataAbstractTpl<Scalar> ActivationDataAbstract;
  typedef ActivationDataExpBarrierTpl<Scalar> Data;
  typedef typename MathBase::VectorXs VectorXs;
  typedef typename MathBase::MatrixXs MatrixXs;

  /*
   * @brief Initialize the quadratic-flat-exp activation model
   *
   * The default `alpha` value is defined as 1.
   *
   * @param[in] nr     Dimension of the residual vector
   * @param[in] alpha  Width of quadratic basin (default: 1.)
   */

  explicit ActivationModelExpBarrierTpl(const std::size_t nr, 
                                        const Scalar threshold, 
                                        const Scalar alpha = (Scalar) 10.)
                                         
      : Base(nr), threshold_(threshold), alpha_(alpha) {
    if (alpha < Scalar(0.)) {
      throw_pretty("Invalid argument: "
                   << "alpha should be a positive value");
    }
  };
  virtual ~ActivationModelExpBarrierTpl(){};

  /*
   * @brief Compute the quadratic-flat-exp function
   *
   * @param[in] data  Exp barrier activation data
   * @param[in] r     Scalar output from the signed distance function
   */
  virtual void calc(const boost::shared_ptr<ActivationDataAbstract> &data,
                    const Eigen::Ref<const VectorXs> &r) {
    if (static_cast<std::size_t>(r.size()) != nr_) {
      throw_pretty("Invalid argument: "
                   << "r has wrong dimension (it should be " +
                          std::to_string(nr_) + ")");
    }
    boost::shared_ptr<Data> d = boost::static_pointer_cast<Data>(data);

    d->d = r.norm();
    if (d->d < threshold_) {
      data->a_value = exp(alpha_ * (threshold_ - d->d)); // all scalars
    } else {
      data->a_value = Scalar(0.0);
    }
  };

  /*
   * @brief Compute the derivatives of the quadratic-flat-exp function
   *
   * @param[in] data  Exp barrier activation data
   * @param[in] r     Scalar output from the signed distance function
   */
  virtual void calcDiff(const boost::shared_ptr<ActivationDataAbstract> &data,
                        const Eigen::Ref<const VectorXs> &r) {
    if (static_cast<std::size_t>(r.size()) != nr_) {
      throw_pretty("Invalid argument: "
                   << "r has wrong dimension (it should be " +
                          std::to_string(nr_) + ")");
    }
    boost::shared_ptr<Data> d = boost::static_pointer_cast<Data>(data);

    if (d->d < threshold_) {
      d->a0 = -alpha_ * exp(alpha_ * (threshold_ - d->d)) / d->d;
      data->Ar =  d->a0 * r;
      data->Arr.diagonal() =
       r.array().square() * std::pow(d->a0, 2);  // GN Hessian approximation (also diagnonal approximation :D)
    } else {
      data->Ar.setZero();
      data->Arr.setZero();
    }
  };

  /**
   * @brief Create the quadratic-flat-exp activation data
   *
   * @return the activation data
   */
  virtual boost::shared_ptr<ActivationDataAbstract> createData() {
    boost::shared_ptr<Data> data =
        boost::allocate_shared<Data>(Eigen::aligned_allocator<Data>(), this);
    return data;
  };

  Scalar get_alpha() const { return alpha_; }
  void set_alpha(const Scalar alpha) { alpha_ = alpha; }

  Scalar get_threshold() const { return threshold_; };
  void set_threshold(const Scalar threshold) { threshold_ = threshold; }

  /**
   * @brief Print relevant information of the quadratic flat-exp model
   *
   * @param[out] os  Output stream object
   */
  virtual void print(std::ostream &os) const {
    os << "ActivationModelExpBarrier {nr=" << nr_ << ", a=" << alpha_ << ", threshold:"<< threshold_ <<"}";
  }

 protected:
  using Base::nr_;  //!< Dimension of the residual vector

 private:
  Scalar threshold_;
  Scalar alpha_;
};

/*
 * @brief Data structure of the quadratic-flat-exp activation
 *
 * @param[in] a0  computed in calc to avoid recomputation
 * @param[in] a1  computed in calcDiff to avoid recomputation
 */
template <typename _Scalar>
struct ActivationDataExpBarrierTpl
    : public ActivationDataAbstractTpl<_Scalar> {
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef _Scalar Scalar;
  typedef MathBaseTpl<Scalar> MathBase;
  typedef ActivationDataAbstractTpl<Scalar> Base;

  template <typename Activation>
  explicit ActivationDataExpBarrierTpl(Activation *const activation)
      : Base(activation), a0(0), d(0) {}

  Scalar a0;
  Scalar d;  //!< Norm of the residual

  using Base::a_value;
  using Base::Ar;
  using Base::Arr;
};

}  // namespace crocoddyl

#endif  // CROCODDYL_CORE_ACTIVATIONS_EXP_BARRIER_HPP_
