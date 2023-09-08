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
 *
 * This activation function describes a quadratic exponential activation
 * depending on the square norm of a residual vector, i.e. \f[ \begin{equation}
 * 1 - exp(\|\mathbf{r}\|^2 / \alpha) \end{equation} \f] where \f$\alpha\f$
 * defines the width of the quadratic basin, \f$r\f$ is the scalar residual,
 * \f$nr\f$ is the dimension of the residual vector. Far
 * away from zero, the quadFlat activation is nearly flat.
 *
 * The computation of the function and it derivatives are carried out in
 * `calc()` and `caldDiff()`, respectively.
 *
 * \sa `calc()`, `calcDiff()`, `createData()`
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

  explicit ActivationModelExpBarrierTpl(const Scalar alpha = (Scalar) -1000.)
                                         
      : Base(1), alpha_(alpha) {
    if (alpha > Scalar(0.)) {
      throw_pretty("Invalid argument: "
                   << "alpha should be a negative value");
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

    d->a0 = exp(alpha_ * (Scalar)r(0,0)); //exp(-r.squaredNorm() / alpha_);
    data->a_value = d->a0;
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
    d->a1 = alpha_ * d->a0;
    data->Ar.setConstant(d->a1) ;
    data->Arr.diagonal().setConstant(alpha_ * d->a1);
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

  Scalar get_alpha() const { return alpha_; };
  void set_alpha(const Scalar alpha) { alpha_ = alpha; };

  /**
   * @brief Print relevant information of the quadratic flat-exp model
   *
   * @param[out] os  Output stream object
   */
  virtual void print(std::ostream &os) const {
    os << "ActivationModelQuadFlatExp {nr=" << nr_ << ", a=" << alpha_ << "}";
  }

 protected:
  using Base::nr_;  //!< Dimension of the residual vector

 private:
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
      : Base(activation), a0(0), a1(0) {}

  Scalar a0;
  Scalar a1;
};

}  // namespace crocoddyl

#endif  // CROCODDYL_CORE_ACTIVATIONS_EXP_BARRIER_HPP_
