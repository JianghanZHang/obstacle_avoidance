///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2021-2023, LAAS-CNRS, Heriot-Watt University
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include "crocoddyl/core/activations/exponential-barrier.hpp"

#include "python/crocoddyl/core/activation-base.hpp"
#include "python/crocoddyl/core/core.hpp"
#include "python/crocoddyl/utils/copyable.hpp"

namespace crocoddyl {
namespace python {

void exposeActivationExpBarrier() {
  bp::class_<ActivationModelExpBarrier, bp::bases<ActivationModelAbstract> >(
      "ActivationModelExpBarrier",
      "An exponential barrier activation model for a defined barrier alpha\n\n",
      bp::init<std::size_t, double, bp::optional<double> >(
          bp::args("self", "nr", "threshold", "alpha"),
          "Initialize the activation model.\n\n"
          ":param nr: dimension of the cost-residual vector\n"
          ":param threshold: activation threshold \n"
          ":param alpha: the cofficient of the exponential barrier (default 10)\n"
          "using Gauss-Newton approximation"))
      .def("calc", &ActivationModelExpBarrier::calc,
           bp::args("self", "data", "r"),
           "Compute the activation value.\n\n"
           ":param data: activation data\n"
           ":param r: residual vector")
      .def("calcDiff", &ActivationModelExpBarrier::calcDiff,
           bp::args("self", "data", "r"),
           "Compute the derivatives of the collision function.\n\n"
           ":param data: activation data\n"
           ":param r: residual vector \n")
      .def("createData", &ActivationModelExpBarrier::createData,
           bp::args("self"), "Create the collision activation data.\n\n")
      .add_property(
          "alpha",
          bp::make_function(&ActivationModelExpBarrier::get_alpha,
                            bp::return_value_policy<bp::return_by_value>()),
          bp::make_function(&ActivationModelExpBarrier::set_alpha), "alpha")
      .add_property(
          "threshold",
          bp::make_function(&ActivationModelExpBarrier::get_threshold,
                            bp::return_value_policy<bp::return_by_value>()),
          bp::make_function(&ActivationModelExpBarrier::set_threshold), "threshold")
      .def(CopyableVisitor<ActivationModelExpBarrier>());
}

}  // namespace python
}  // namespace crocoddyl
