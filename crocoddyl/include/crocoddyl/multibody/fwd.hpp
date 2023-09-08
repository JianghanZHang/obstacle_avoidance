///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2019-2022, LAAS-CNRS, University of Edinburgh, INRIA
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef CROCODDYL_MULTIBODY_FWD_HPP_
#define CROCODDYL_MULTIBODY_FWD_HPP_

#include "crocoddyl/core/costs/residual.hpp"
#include "crocoddyl/core/utils/deprecate.hpp"

namespace crocoddyl {

// actuation
template <typename Scalar>
class ActuationModelFloatingBaseTpl;

template <typename Scalar>
class ActuationModelFullTpl;

template <typename Scalar>
class ActuationModelMultiCopterBaseTpl;

// force
template <typename Scala>
struct ForceDataAbstractTpl;

// contact
template <typename Scalar>
class ContactModelAbstractTpl;
template <typename Scalar>
struct ContactDataAbstractTpl;

// action
template <typename Scalar>
class ActionModelImpulseFwdDynamicsTpl;
template <typename Scalar>
struct ActionDataImpulseFwdDynamicsTpl;

// differential action
template <typename Scalar>
class DifferentialActionModelFreeFwdDynamicsTpl;
template <typename Scalar>
struct DifferentialActionDataFreeFwdDynamicsTpl;

template <typename Scalar>
class DifferentialActionModelFreeInvDynamicsTpl;
template <typename Scalar>
struct DifferentialActionDataFreeInvDynamicsTpl;

template <typename Scalar>
class DifferentialActionModelContactFwdDynamicsTpl;
template <typename Scalar>
struct DifferentialActionDataContactFwdDynamicsTpl;

template <typename Scalar>
class DifferentialActionModelContactInvDynamicsTpl;
template <typename Scalar>
struct DifferentialActionDataContactInvDynamicsTpl;

// numdiff
template <typename Scalar>
class CostModelNumDiffTpl;
template <typename Scalar>
struct CostDataNumDiffTpl;

template <typename Scalar>
class ContactModelNumDiffTpl;
template <typename Scalar>
struct ContactDataNumDiffTpl;

// frame
template <typename Scalar>
struct FrameTranslationTpl;

template <typename Scalar>
struct FrameRotationTpl;

template <typename Scalar>
struct FramePlacementTpl;

template <typename Scalar>
struct FrameMotionTpl;

template <typename Scalar>
struct FrameForceTpl;

template <typename Scalar>
struct FrameFrictionConeTpl;

template <typename Scalar>
struct FrameWrenchConeTpl;

template <typename Scalar>
struct FrameCoPSupportTpl;

// residual
template <typename Scalar>
class ResidualModelCentroidalMomentumTpl;
template <typename Scalar>
struct ResidualDataCentroidalMomentumTpl;

template <typename Scalar>
class ResidualModelCoMPositionTpl;
template <typename Scalar>
struct ResidualDataCoMPositionTpl;

template <typename Scalar>
class ResidualModelContactForceTpl;
template <typename Scalar>
struct ResidualDataContactForceTpl;

template <typename Scalar>
class ResidualModelContactFrictionConeTpl;
template <typename Scalar>
struct ResidualDataContactFrictionConeTpl;

template <typename Scalar>
class ResidualModelContactCoPPositionTpl;
template <typename Scalar>
struct ResidualDataContactCoPPositionTpl;

template <typename Scalar>
class ResidualModelContactWrenchConeTpl;
template <typename Scalar>
struct ResidualDataContactWrenchConeTpl;

template <typename Scalar>
class ResidualModelContactControlGravTpl;
template <typename Scalar>
struct ResidualDataContactControlGravTpl;

template <typename Scalar>
class ResidualModelControlGravTpl;
template <typename Scalar>
struct ResidualDataControlGravTpl;

template <typename Scalar>
class ResidualModelFramePlacementTpl;
template <typename Scalar>
struct ResidualDataFramePlacementTpl;

template <typename Scalar>
class ResidualModelFrameRotationTpl;
template <typename Scalar>
struct ResidualDataFrameRotationTpl;

template <typename Scalar>
class ResidualModelFrameTranslationTpl;
template <typename Scalar>
struct ResidualDataFrameTranslationTpl;

template <typename Scalar>
class ResidualModelFrameVelocityTpl;
template <typename Scalar>
struct ResidualDataFrameVelocityTpl;

template <typename Scalar>
class ResidualModelFrameDistanceTpl;
template <typename Scalar>
struct ResidualDataFrameDistanceTpl;

template <typename Scalar>
class ResidualModelImpulseCoMTpl;
template <typename Scalar>
struct ResidualDataImpulseCoMTpl;

template <typename Scalar>
class ResidualModelStateTpl;
template <typename Scalar>
struct ResidualDataStateTpl;

#ifdef PINOCCHIO_WITH_HPP_FCL
template <typename Scalar>
class ResidualModelPairCollisionTpl;
template <typename Scalar>
struct ResidualDataPairCollisionTpl;
#endif

// impulse
template <typename Scalar>
class ImpulseModelAbstractTpl;
template <typename Scalar>
struct ImpulseDataAbstractTpl;

// contact
template <typename Scalar>
struct ContactItemTpl;
template <typename Scalar>
class ContactModelMultipleTpl;
template <typename Scalar>
struct ContactDataMultipleTpl;

template <typename Scalar>
class ContactModel1DTpl;
template <typename Scalar>
struct ContactData1DTpl;

template <typename Scalar>
class ContactModel2DTpl;
template <typename Scalar>
struct ContactData2DTpl;

template <typename Scalar>
class ContactModel3DTpl;
template <typename Scalar>
struct ContactData3DTpl;

template <typename Scalar>
class ContactModel6DTpl;
template <typename Scalar>
struct ContactData6DTpl;

// friction
template <typename Scalar>
class FrictionConeTpl;
template <typename Scalar>
class WrenchConeTpl;

// cop support
template <typename Scalar>
class CoPSupportTpl;

// state
template <typename Scalar>
class StateMultibodyTpl;

// data collector
template <typename Scalar>
struct DataCollectorMultibodyTpl;

template <typename Scalar>
struct DataCollectorActMultibodyTpl;

template <typename Scalar>
struct DataCollectorJointActMultibodyTpl;

template <typename Scalar>
struct DataCollectorContactTpl;

template <typename Scalar>
struct DataCollectorMultibodyInContactTpl;

template <typename Scalar>
struct DataCollectorActMultibodyInContactTpl;

template <typename Scalar>
struct DataCollectorJointActMultibodyInContactTpl;

template <typename Scalar>
struct DataCollectorImpulseTpl;

template <typename Scalar>
struct DataCollectorMultibodyInImpulseTpl;

// impulse
template <typename Scalar>
class ImpulseModel6DTpl;
template <typename Scalar>
struct ImpulseData6DTpl;

template <typename Scalar>
class ImpulseModel3DTpl;
template <typename Scalar>
struct ImpulseData3DTpl;

template <typename Scalar>
struct ImpulseItemTpl;
template <typename Scalar>
class ImpulseModelMultipleTpl;
template <typename Scalar>
struct ImpulseDataMultipleTpl;

/*******************************Template
 * Instantiation**************************/

typedef ActuationModelFloatingBaseTpl<double> ActuationModelFloatingBase;
typedef ActuationModelFullTpl<double> ActuationModelFull;
typedef ActuationModelMultiCopterBaseTpl<double> ActuationModelMultiCopterBase;

typedef ForceDataAbstractTpl<double> ForceDataAbstract;

typedef ContactModelAbstractTpl<double> ContactModelAbstract;
typedef ContactDataAbstractTpl<double> ContactDataAbstract;

typedef ActionModelImpulseFwdDynamicsTpl<double> ActionModelImpulseFwdDynamics;
typedef ActionDataImpulseFwdDynamicsTpl<double> ActionDataImpulseFwdDynamics;

typedef DifferentialActionModelFreeFwdDynamicsTpl<double>
    DifferentialActionModelFreeFwdDynamics;
typedef DifferentialActionDataFreeFwdDynamicsTpl<double>
    DifferentialActionDataFreeFwdDynamics;
typedef DifferentialActionModelFreeInvDynamicsTpl<double>
    DifferentialActionModelFreeInvDynamics;
typedef DifferentialActionDataFreeInvDynamicsTpl<double>
    DifferentialActionDataFreeInvDynamics;
typedef DifferentialActionModelContactFwdDynamicsTpl<double>
    DifferentialActionModelContactFwdDynamics;
typedef DifferentialActionDataContactFwdDynamicsTpl<double>
    DifferentialActionDataContactFwdDynamics;
typedef DifferentialActionModelContactInvDynamicsTpl<double>
    DifferentialActionModelContactInvDynamics;
typedef DifferentialActionDataContactInvDynamicsTpl<double>
    DifferentialActionDataContactInvDynamics;

typedef CostModelNumDiffTpl<double> CostModelNumDiff;
typedef CostDataNumDiffTpl<double> CostDataNumDiff;
typedef ContactModelNumDiffTpl<double> ContactModelNumDiff;
typedef ContactDataNumDiffTpl<double> ContactDataNumDiff;

typedef FrictionConeTpl<double> FrictionCone;
typedef WrenchConeTpl<double> WrenchCone;
typedef CoPSupportTpl<double> CoPSupport;

DEPRECATED("Do not use FrameTranslation",
           typedef FrameTranslationTpl<double> FrameTranslation;)
DEPRECATED("Do not use FrameTranslation",
           typedef FrameRotationTpl<double> FrameRotation;)
DEPRECATED("Do not use FramePlacement",
           typedef FramePlacementTpl<double> FramePlacement;)
DEPRECATED("Do not use FrameMotion",
           typedef FrameMotionTpl<double> FrameMotion;)
DEPRECATED("Do not use FrameForce", typedef FrameForceTpl<double> FrameForce;)
DEPRECATED("Do not use FrameFrictionCone",
           typedef FrameFrictionConeTpl<double> FrameFrictionCone;)
DEPRECATED("Do not use FrameWrenchCone",
           typedef FrameWrenchConeTpl<double> FrameWrenchCone;)
DEPRECATED("Do not use FrameCopSupport",
           typedef FrameCoPSupportTpl<double> FrameCoPSupport;)

typedef ResidualModelCentroidalMomentumTpl<double>
    ResidualModelCentroidalMomentum;
typedef ResidualDataCentroidalMomentumTpl<double>
    ResidualDataCentroidalMomentum;
typedef ResidualModelCoMPositionTpl<double> ResidualModelCoMPosition;
typedef ResidualDataCoMPositionTpl<double> ResidualDataCoMPosition;
typedef ResidualModelContactForceTpl<double> ResidualModelContactForce;
typedef ResidualDataContactForceTpl<double> ResidualDataContactForce;
typedef ResidualModelContactFrictionConeTpl<double>
    ResidualModelContactFrictionCone;
typedef ResidualDataContactFrictionConeTpl<double>
    ResidualDataContactFrictionCone;
typedef ResidualModelContactCoPPositionTpl<double>
    ResidualModelContactCoPPosition;
typedef ResidualDataContactCoPPositionTpl<double>
    ResidualDataContactCoPPosition;
typedef ResidualModelContactWrenchConeTpl<double>
    ResidualModelContactWrenchCone;
typedef ResidualDataContactWrenchConeTpl<double> ResidualDataContactWrenchCone;
typedef ResidualModelContactControlGravTpl<double>
    ResidualModelContactControlGrav;
typedef ResidualDataContactControlGravTpl<double>
    ResidualDataContactControlGrav;
typedef ResidualModelControlGravTpl<double> ResidualModelControlGrav;
typedef ResidualDataControlGravTpl<double> ResidualDataControlGrav;
typedef ResidualModelFramePlacementTpl<double> ResidualModelFramePlacement;
typedef ResidualDataFramePlacementTpl<double> ResidualDataFramePlacement;
typedef ResidualModelFrameRotationTpl<double> ResidualModelFrameRotation;
typedef ResidualDataFrameRotationTpl<double> ResidualDataFrameRotation;
typedef ResidualModelFrameTranslationTpl<double> ResidualModelFrameTranslation;
typedef ResidualDataFrameTranslationTpl<double> ResidualDataFrameTranslation;
typedef ResidualModelFrameVelocityTpl<double> ResidualModelFrameVelocity;
typedef ResidualDataFrameVelocityTpl<double> ResidualDataFrameVelocity;
typedef ResidualModelFrameDistanceTpl<double> ResidualModelFrameDistance;
typedef ResidualDataFrameDistanceTpl<double> ResidualDataFrameDistance;
typedef ResidualModelImpulseCoMTpl<double> ResidualModelImpulseCoM;
typedef ResidualDataImpulseCoMTpl<double> ResidualDataImpulseCoM;
typedef ResidualModelStateTpl<double> ResidualModelState;
typedef ResidualDataStateTpl<double> ResidualDataState;

#ifdef PINOCCHIO_WITH_HPP_FCL
typedef ResidualModelPairCollisionTpl<double> ResidualModelPairCollision;
typedef ResidualDataPairCollisionTpl<double> ResidualDataPairCollision;
#endif

typedef ImpulseModelAbstractTpl<double> ImpulseModelAbstract;
typedef ImpulseDataAbstractTpl<double> ImpulseDataAbstract;

enum ContactType {
  ContactUndefined,
  Contact1D,
  Contact2D,
  Contact3D,
  Contact6D
};
enum ImpulseType { ImpulseUndefined, Impulse3D, Impulse6D };

typedef ContactItemTpl<double> ContactItem;
typedef ContactModelMultipleTpl<double> ContactModelMultiple;
typedef ContactDataMultipleTpl<double> ContactDataMultiple;
typedef ContactModel1DTpl<double> ContactModel1D;
typedef ContactData1DTpl<double> ContactData1D;
typedef ContactModel2DTpl<double> ContactModel2D;
typedef ContactData2DTpl<double> ContactData2D;
typedef ContactModel3DTpl<double> ContactModel3D;
typedef ContactData3DTpl<double> ContactData3D;
typedef ContactModel6DTpl<double> ContactModel6D;
typedef ContactData6DTpl<double> ContactData6D;

typedef StateMultibodyTpl<double> StateMultibody;

typedef DataCollectorMultibodyTpl<double> DataCollectorMultibody;
typedef DataCollectorActMultibodyTpl<double> DataCollectorActMultibody;
typedef DataCollectorJointActMultibodyTpl<double>
    DataCollectorJointActMultibody;
typedef DataCollectorContactTpl<double> DataCollectorContact;
typedef DataCollectorMultibodyInContactTpl<double>
    DataCollectorMultibodyInContact;
typedef DataCollectorActMultibodyInContactTpl<double>
    DataCollectorActMultibodyInContact;
typedef DataCollectorJointActMultibodyInContactTpl<double>
    DataCollectorJointActMultibodyInContact;
typedef DataCollectorImpulseTpl<double> DataCollectorImpulse;
typedef DataCollectorMultibodyInImpulseTpl<double>
    DataCollectorMultibodyInImpulse;

typedef ImpulseModel6DTpl<double> ImpulseModel6D;
typedef ImpulseData6DTpl<double> ImpulseData6D;
typedef ImpulseModel3DTpl<double> ImpulseModel3D;
typedef ImpulseData3DTpl<double> ImpulseData3D;
typedef ImpulseItemTpl<double> ImpulseItem;
typedef ImpulseModelMultipleTpl<double> ImpulseModelMultiple;
typedef ImpulseDataMultipleTpl<double> ImpulseDataMultiple;

}  // namespace crocoddyl

#endif  // CROCODDYL_MULTIBODY_FWD_HPP_