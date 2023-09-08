///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2021-2023, University of Edinburgh, Heriot-Watt University
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include "crocoddyl/multibody/residuals/frame-distance.hpp"

#include "python/crocoddyl/multibody/multibody.hpp"
#include "python/crocoddyl/utils/copyable.hpp"

namespace crocoddyl {
namespace python {

void exposeResidualFrameDistance() {
  bp::register_ptr_to_python<
      boost::shared_ptr<ResidualModelFrameDistance> >();

  bp::class_<ResidualModelFrameDistance, bp::bases<ResidualModelAbstract> >(
      "ResidualModelFrameDistance",
      "This residual function defines the the frame translation tracking as as "
      "r = t - tref, with t and tref as the\n"
      "current and reference frame translations, respectively.",
      bp::init<boost::shared_ptr<StateMultibody>, pinocchio::FrameIndex,
               Eigen::Vector3d, std::size_t>(
          bp::args("self", "state", "id", "xref", "nu"),
          "Initialize the frame translation residual model.\n\n"
          ":param state: state of the multibody system\n"
          ":param id: reference frame id\n"
          ":param xref: reference frame translation\n"
          ":param nu: dimension of control vector"))
      .def(bp::init<boost::shared_ptr<StateMultibody>, pinocchio::FrameIndex,
                    Eigen::Vector3d>(
          bp::args("self", "state", "id", "xref"),
          "Initialize the frame translation residual model.\n\n"
          "The default nu is obtained from state.nv.\n"
          ":param state: state of the multibody system\n"
          ":param id: reference frame id\n"
          ":param xref: reference frame translation"))
      .def<void (ResidualModelFrameDistance::*)(
          const boost::shared_ptr<ResidualDataAbstract>&,
          const Eigen::Ref<const Eigen::VectorXd>&,
          const Eigen::Ref<const Eigen::VectorXd>&)>(
          "calc", &ResidualModelFrameDistance::calc,
          bp::args("self", "data", "x", "u"),
          "Compute the frame translation residual.\n\n"
          ":param data: residual data\n"
          ":param x: state point (dim. state.nx)\n"
          ":param u: control input (dim. nu)")
      .def<void (ResidualModelFrameDistance::*)(
          const boost::shared_ptr<ResidualDataAbstract>&,
          const Eigen::Ref<const Eigen::VectorXd>&)>(
          "calc", &ResidualModelAbstract::calc, bp::args("self", "data", "x"))
      .def<void (ResidualModelFrameDistance::*)(
          const boost::shared_ptr<ResidualDataAbstract>&,
          const Eigen::Ref<const Eigen::VectorXd>&,
          const Eigen::Ref<const Eigen::VectorXd>&)>(
          "calcDiff", &ResidualModelFrameDistance::calcDiff,
          bp::args("self", "data", "x", "u"),
          "Compute the derivatives of the frame translation residual.\n\n"
          "It assumes that calc has been run first.\n"
          ":param data: action data\n"
          ":param x: state point (dim. state.nx)\n"
          ":param u: control input (dim. nu)")
      .def<void (ResidualModelFrameDistance::*)(
          const boost::shared_ptr<ResidualDataAbstract>&,
          const Eigen::Ref<const Eigen::VectorXd>&)>(
          "calcDiff", &ResidualModelAbstract::calcDiff,
          bp::args("self", "data", "x"))
      .def("createData", &ResidualModelFrameDistance::createData,
           bp::with_custodian_and_ward_postcall<0, 2>(),
           bp::args("self", "data"),
           "Create the frame translation residual data.\n\n"
           "Each residual model has its own data that needs to be allocated. "
           "This function\n"
           "returns the allocated data for the frame translation residual.\n"
           ":param data: shared data\n"
           ":return residual data.")
      .add_property("id", &ResidualModelFrameDistance::get_id,
                    &ResidualModelFrameDistance::set_id,
                    "reference frame id")
      .add_property(
          "reference",
          bp::make_function(&ResidualModelFrameDistance::get_reference,
                            bp::return_internal_reference<>()),
          &ResidualModelFrameDistance::set_reference,
          "reference frame translation")
      .def(CopyableVisitor<ResidualModelFrameDistance>());

  bp::register_ptr_to_python<
      boost::shared_ptr<ResidualDataFrameDistance> >();

  bp::class_<ResidualDataFrameDistance, bp::bases<ResidualDataAbstract> >(
      "ResidualDataFrameDistance",
      "Data for frame translation residual.\n\n",
      bp::init<ResidualModelFrameDistance*, DataCollectorAbstract*>(
          bp::args("self", "model", "data"),
          "Create frame translation residual data.\n\n"
          ":param model: frame translation residual model\n"
          ":param data: shared data")[bp::with_custodian_and_ward<
          1, 2, bp::with_custodian_and_ward<1, 3> >()])
      .add_property("pinocchio",
                    bp::make_getter(&ResidualDataFrameDistance::pinocchio,
                                    bp::return_internal_reference<>()),
                    "pinocchio data")
      .add_property("fJf",
                    bp::make_getter(&ResidualDataFrameDistance::fJf,
                                    bp::return_internal_reference<>()),
                    "local Jacobian of the frame")
      .def(CopyableVisitor<ResidualDataFrameDistance>());
}

}  // namespace python
}  // namespace crocoddyl
