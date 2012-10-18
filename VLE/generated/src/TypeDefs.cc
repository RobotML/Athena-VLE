// 
// Includes ----------------------------------------------------------------------
// 

#include <iostream>		
#include <string.h> 	

#include "TypeDefs.h"

using namespace std;

namespace generated
{

// 
// Data type implementations ----------------------------------------------------------
//

// -------------------------------------------------------- Pointer
void init_Pointer(Pointer& data) {
	data = NULL;
}

		
// -------------------------------------------------------- String
void init_String(String& data) {
	data = "";
}

		
// -------------------------------------------------------- Logical
void init_Logical(Logical& data) {
	data = false;
}

		
// -------------------------------------------------------- Int
void init_Int(Int& data) {
	data = 0;
}

		
// -------------------------------------------------------- Long
void init_Long(Long& data) {
	data = 0;
}

		
// -------------------------------------------------------- Real
void init_Real(Real& data) {
	data = 0;
}

		
// -------------------------------------------------------- Vec3
void init_Vec3(Vec3& data) {} 
		
// -------------------------------------------------------- Vec5
void init_Vec5(Vec5& data) {} 
		
// -------------------------------------------------------- VecX
VecX VecX_allocate(unsigned int x, unsigned int y) {
	return new boost::multi_array<Real, 2>(boost::extents [x][y]);
}
void init_VecX(VecX& data) {} 
		
// -------------------------------------------------------- gisement
void init_gisement(gisement& data) {
	init_Real(data);
}
		
// -------------------------------------------------------- site
void init_site(site& data) {
	init_Real(data);
}
		
// -------------------------------------------------------- VecOne
VecOne VecOne_allocate(unsigned int x) {
	return new boost::multi_array<gisement, 1>(boost::extents [x]);
}
void init_VecOne(VecOne& data) {} 
		
// -------------------------------------------------------- VecY
void init_VecY(VecY& data) {} 
		
// -------------------------------------------------------- test3
test3::test3(const test3& _test3) {
	copy(_test3);
}
test3& test3::operator = (const test3& _test3) {
	copy(_test3);
	return *this;
}
void test3::copy(const test3& _test3) {
	hello = _test3.hello;
	g = _test3.g;
}
void init_test3(test3& data) { 
	init_Real(data.hello);
	init_gisement(data.g);
}
		
// -------------------------------------------------------- Ints
void init_Ints(Ints& data) {}
		
// -------------------------------------------------------- Longs
void init_Longs(Longs& data) {}
		
// -------------------------------------------------------- Reals
void init_Reals(Reals& data) {}
		
// -------------------------------------------------------- EntityType
void init_EntityType(EntityType& data) {
	data = ABSTRACT_ENTITY;
}

		
// -------------------------------------------------------- NetworkID
void init_NetworkID(NetworkID& data) {
	data = INVALID_NETWORK;
}

		
// -------------------------------------------------------- SensorType
void init_SensorType(SensorType& data) {
	data = INVALID_SENSOR_TYPE;
}

		
// -------------------------------------------------------- SensorFunction
void init_SensorFunction(SensorFunction& data) {
	data = INVALID_SENSOR_FUNCTION;
}

		
// -------------------------------------------------------- EquipmentType
void init_EquipmentType(EquipmentType& data) {
	data = PLATFORM;
}

		
// -------------------------------------------------------- EquipmentStatus
EquipmentStatus::EquipmentStatus(const EquipmentStatus& _EquipmentStatus) {
	copy(_EquipmentStatus);
}
EquipmentStatus& EquipmentStatus::operator = (const EquipmentStatus& _EquipmentStatus) {
	copy(_EquipmentStatus);
	return *this;
}
void EquipmentStatus::copy(const EquipmentStatus& _EquipmentStatus) {
	type = _EquipmentStatus.type;
	id = _EquipmentStatus.id;
	available = _EquipmentStatus.available;
	enabled = _EquipmentStatus.enabled;
}
void init_EquipmentStatus(EquipmentStatus& data) { 
	init_Long(data.type);
	init_Long(data.id);
	init_Long(data.available);
	data.available = 100;
	init_Long(data.enabled);
	data.enabled = 0;
}
		
// -------------------------------------------------------- EquipmentStatusList
void init_EquipmentStatusList(EquipmentStatusList& data) {}
		
// -------------------------------------------------------- ExternalInput
ExternalInput::ExternalInput(const ExternalInput& _ExternalInput) {
	copy(_ExternalInput);
}
ExternalInput& ExternalInput::operator = (const ExternalInput& _ExternalInput) {
	copy(_ExternalInput);
	return *this;
}
void ExternalInput::copy(const ExternalInput& _ExternalInput) {
	id = _ExternalInput.id;
	duration = _ExternalInput.duration;
	available_during = _ExternalInput.available_during;
	available_after = _ExternalInput.available_after;
}
void init_ExternalInput(ExternalInput& data) { 
	init_Long(data.id);
	init_Long(data.duration);
	init_Long(data.available_during);
	init_Long(data.available_after);
}
		
// -------------------------------------------------------- vExternalInput
void init_vExternalInput(vExternalInput& data) {}
		
// -------------------------------------------------------- ExternalInputListForOneTypeOfEquipment
void init_ExternalInputListForOneTypeOfEquipment(ExternalInputListForOneTypeOfEquipment& data) {}
		
// -------------------------------------------------------- ExternalInputList
void init_ExternalInputList(ExternalInputList& data) {}
		
// -------------------------------------------------------- EntityState
EntityState::EntityState(const EntityState& _EntityState) {
	copy(_EntityState);
}
EntityState& EntityState::operator = (const EntityState& _EntityState) {
	copy(_EntityState);
	return *this;
}
void EntityState::copy(const EntityState& _EntityState) {
	time = _EntityState.time;
	id = _EntityState.id;
	side = _EntityState.side;
	type = _EntityState.type;
	subtype = _EntityState.subtype;
	subsubtype = _EntityState.subsubtype;
	memcpy((void*)position, (void*)_EntityState.position, sizeof(Vec3));
	memcpy((void*)speed, (void*)_EntityState.speed, sizeof(Vec3));
	memcpy((void*)attitudes, (void*)_EntityState.attitudes, sizeof(Vec3));
}
void init_EntityState(EntityState& data) { 
	init_Long(data.time);
	init_Long(data.id);
	init_Long(data.side);
	init_EntityType(data.type);
	init_Long(data.subtype);
	init_Long(data.subsubtype);
	init_Vec3(data.position);
	init_Vec3(data.speed);
	init_Vec3(data.attitudes);
}
		
// -------------------------------------------------------- EntityStates
void init_EntityStates(EntityStates& data) {}
		
// -------------------------------------------------------- EmitterBeam
EmitterBeam::EmitterBeam(const EmitterBeam& _EmitterBeam) {
	copy(_EmitterBeam);
}
EmitterBeam& EmitterBeam::operator = (const EmitterBeam& _EmitterBeam) {
	copy(_EmitterBeam);
	return *this;
}
void EmitterBeam::copy(const EmitterBeam& _EmitterBeam) {
	elevation = _EmitterBeam.elevation;
	azimut = _EmitterBeam.azimut;
	elevationAperture = _EmitterBeam.elevationAperture;
	azimutAperture = _EmitterBeam.azimutAperture;
	targets = _EmitterBeam.targets;
}
void init_EmitterBeam(EmitterBeam& data) { 
	init_Real(data.elevation);
	init_Real(data.azimut);
	init_Real(data.elevationAperture);
	init_Real(data.azimutAperture);
	init_Longs(data.targets);
}
		
// -------------------------------------------------------- Beams
void init_Beams(Beams& data) {}
		
// -------------------------------------------------------- EmitterState
EmitterState::EmitterState(const EmitterState& _EmitterState) {
	copy(_EmitterState);
}
EmitterState& EmitterState::operator = (const EmitterState& _EmitterState) {
	copy(_EmitterState);
	return *this;
}
void EmitterState::copy(const EmitterState& _EmitterState) {
	time = _EmitterState.time;
	entityID = _EmitterState.entityID;
	type = _EmitterState.type;
	techno = _EmitterState.techno;
	dist1m2 = _EmitterState.dist1m2;
	beams = _EmitterState.beams;
}
void init_EmitterState(EmitterState& data) { 
	init_Long(data.time);
	init_Long(data.entityID);
	init_SensorType(data.type);
	init_Long(data.techno);
	init_Real(data.dist1m2);
	init_Beams(data.beams);
}
		
// -------------------------------------------------------- EmitterStates
void init_EmitterStates(EmitterStates& data) {}
		
// -------------------------------------------------------- JammerState
JammerState::JammerState(const JammerState& _JammerState) {
	copy(_JammerState);
}
JammerState& JammerState::operator = (const JammerState& _JammerState) {
	copy(_JammerState);
	return *this;
}
void JammerState::copy(const JammerState& _JammerState) {
	time = _JammerState.time;
	entityID = _JammerState.entityID;
	type = _JammerState.type;
	techno = _JammerState.techno;
	elevation = _JammerState.elevation;
	azimut = _JammerState.azimut;
	apertureEl = _JammerState.apertureEl;
	apertureAz = _JammerState.apertureAz;
	powerOrDistance = _JammerState.powerOrDistance;
}
void init_JammerState(JammerState& data) { 
	init_Long(data.time);
	init_Long(data.entityID);
	init_Long(data.type);
	init_Long(data.techno);
	init_Real(data.elevation);
	init_Real(data.azimut);
	init_Real(data.apertureEl);
	init_Real(data.apertureAz);
	init_Real(data.powerOrDistance);
}
		
// -------------------------------------------------------- JammerStates
void init_JammerStates(JammerStates& data) {}
		
// -------------------------------------------------------- Detonation
Detonation::Detonation(const Detonation& _Detonation) {
	copy(_Detonation);
}
Detonation& Detonation::operator = (const Detonation& _Detonation) {
	copy(_Detonation);
	return *this;
}
void Detonation::copy(const Detonation& _Detonation) {
	time = _Detonation.time;
	shooterID = _Detonation.shooterID;
	weaponType = _Detonation.weaponType;
	targets = _Detonation.targets;
	memcpy((void*)position, (void*)_Detonation.position, sizeof(Vec3));
}
void init_Detonation(Detonation& data) { 
	init_Long(data.time);
	init_Long(data.shooterID);
	init_Long(data.weaponType);
	init_Longs(data.targets);
	init_Vec3(data.position);
}
		
// -------------------------------------------------------- Detonations
void init_Detonations(Detonations& data) {}
		
// -------------------------------------------------------- EnvironmentInteractions
EnvironmentInteractions::EnvironmentInteractions(const EnvironmentInteractions& _EnvironmentInteractions) {
	copy(_EnvironmentInteractions);
}
EnvironmentInteractions& EnvironmentInteractions::operator = (const EnvironmentInteractions& _EnvironmentInteractions) {
	copy(_EnvironmentInteractions);
	return *this;
}
void EnvironmentInteractions::copy(const EnvironmentInteractions& _EnvironmentInteractions) {
	entities = _EnvironmentInteractions.entities;
	emitters = _EnvironmentInteractions.emitters;
	jammers = _EnvironmentInteractions.jammers;
	detonations = _EnvironmentInteractions.detonations;
}
void init_EnvironmentInteractions(EnvironmentInteractions& data) { 
	init_EntityStates(data.entities);
	init_EmitterStates(data.emitters);
	init_JammerStates(data.jammers);
	init_Detonations(data.detonations);
}
		
// -------------------------------------------------------- AngularBounds
AngularBounds::AngularBounds(const AngularBounds& _AngularBounds) {
	copy(_AngularBounds);
}
AngularBounds& AngularBounds::operator = (const AngularBounds& _AngularBounds) {
	copy(_AngularBounds);
	return *this;
}
void AngularBounds::copy(const AngularBounds& _AngularBounds) {
	symetric = _AngularBounds.symetric;
	elevationMin = _AngularBounds.elevationMin;
	elevationMax = _AngularBounds.elevationMax;
	azimutMin = _AngularBounds.azimutMin;
	azimutMax = _AngularBounds.azimutMax;
}
void init_AngularBounds(AngularBounds& data) { 
	init_Long(data.symetric);
	init_Real(data.elevationMin);
	init_Real(data.elevationMax);
	init_Real(data.azimutMin);
	init_Real(data.azimutMax);
}
		
// -------------------------------------------------------- AngularDelta
AngularDelta::AngularDelta(const AngularDelta& _AngularDelta) {
	copy(_AngularDelta);
}
AngularDelta& AngularDelta::operator = (const AngularDelta& _AngularDelta) {
	copy(_AngularDelta);
	return *this;
}
void AngularDelta::copy(const AngularDelta& _AngularDelta) {
	deltaElevation = _AngularDelta.deltaElevation;
	deltaAzimut = _AngularDelta.deltaAzimut;
}
void init_AngularDelta(AngularDelta& data) { 
	init_Real(data.deltaElevation);
	init_Real(data.deltaAzimut);
}
		
// -------------------------------------------------------- SensorAngularBounds
void init_SensorAngularBounds(SensorAngularBounds& data) {}
		
// -------------------------------------------------------- SensorAngularDelta
void init_SensorAngularDelta(SensorAngularDelta& data) {}
		
// -------------------------------------------------------- JammerDefinition
JammerDefinition::JammerDefinition(const JammerDefinition& _JammerDefinition) {
	copy(_JammerDefinition);
}
JammerDefinition& JammerDefinition::operator = (const JammerDefinition& _JammerDefinition) {
	copy(_JammerDefinition);
	return *this;
}
void JammerDefinition::copy(const JammerDefinition& _JammerDefinition) {
	id = _JammerDefinition.id;
	domainId = _JammerDefinition.domainId;
	type = _JammerDefinition.type;
	techno = _JammerDefinition.techno;
	maxPowerAllocation = _JammerDefinition.maxPowerAllocation;
	bounds = _JammerDefinition.bounds;
	maxTargetNumber = _JammerDefinition.maxTargetNumber;
	apertureEl = _JammerDefinition.apertureEl;
	apertureAz = _JammerDefinition.apertureAz;
}
void init_JammerDefinition(JammerDefinition& data) { 
	init_Long(data.id);
	init_Long(data.domainId);
	init_Long(data.type);
	init_Long(data.techno);
	init_Real(data.maxPowerAllocation);
	init_AngularBounds(data.bounds);
	init_Long(data.maxTargetNumber);
	init_Real(data.apertureEl);
	init_Real(data.apertureAz);
}
		
// -------------------------------------------------------- EmitterJammed
EmitterJammed::EmitterJammed(const EmitterJammed& _EmitterJammed) {
	copy(_EmitterJammed);
}
EmitterJammed& EmitterJammed::operator = (const EmitterJammed& _EmitterJammed) {
	copy(_EmitterJammed);
	return *this;
}
void EmitterJammed::copy(const EmitterJammed& _EmitterJammed) {
	entityID = _EmitterJammed.entityID;
	powerAllocation = _EmitterJammed.powerAllocation;
}
void init_EmitterJammed(EmitterJammed& data) { 
	init_Long(data.entityID);
	init_Real(data.powerAllocation);
}
		
// -------------------------------------------------------- EmitterJammList
void init_EmitterJammList(EmitterJammList& data) {}
		
// -------------------------------------------------------- JammerStatus
JammerStatus::JammerStatus(const JammerStatus& _JammerStatus) {
	copy(_JammerStatus);
}
JammerStatus& JammerStatus::operator = (const JammerStatus& _JammerStatus) {
	copy(_JammerStatus);
	return *this;
}
void JammerStatus::copy(const JammerStatus& _JammerStatus) {
	lastUpdateDate = _JammerStatus.lastUpdateDate;
	id = _JammerStatus.id;
	type = _JammerStatus.type;
	techno = _JammerStatus.techno;
	available = _JammerStatus.available;
	endOfOrderId = _JammerStatus.endOfOrderId;
	doingOrderId = _JammerStatus.doingOrderId;
	doingOrderDuration = _JammerStatus.doingOrderDuration;
	errorFlag = _JammerStatus.errorFlag;
	nbrOfJammOps = _JammerStatus.nbrOfJammOps;
}
void init_JammerStatus(JammerStatus& data) { 
	init_Long(data.lastUpdateDate);
	init_Long(data.id);
	init_Long(data.type);
	init_Long(data.techno);
	init_Long(data.available);
	init_Long(data.endOfOrderId);
	init_Long(data.doingOrderId);
	init_Long(data.doingOrderDuration);
	init_Long(data.errorFlag);
	init_Long(data.nbrOfJammOps);
}
		
// -------------------------------------------------------- JammersStatus
void init_JammersStatus(JammersStatus& data) {}
		
// -------------------------------------------------------- JammOp
JammOp::JammOp(const JammOp& _JammOp) {
	copy(_JammOp);
}
JammOp& JammOp::operator = (const JammOp& _JammOp) {
	copy(_JammOp);
	return *this;
}
void JammOp::copy(const JammOp& _JammOp) {
	target_id = _JammOp.target_id;
	azimut = _JammOp.azimut;
	elevation = _JammOp.elevation;
}
void init_JammOp(JammOp& data) { 
	init_Long(data.target_id);
	init_Real(data.azimut);
	init_Real(data.elevation);
}
		
// -------------------------------------------------------- JammOperationList
void init_JammOperationList(JammOperationList& data) {}
		
// -------------------------------------------------------- JammerOrder
JammerOrder::JammerOrder(const JammerOrder& _JammerOrder) {
	copy(_JammerOrder);
}
JammerOrder& JammerOrder::operator = (const JammerOrder& _JammerOrder) {
	copy(_JammerOrder);
	return *this;
}
void JammerOrder::copy(const JammerOrder& _JammerOrder) {
	orderId = _JammerOrder.orderId;
	jammerId = _JammerOrder.jammerId;
	func = _JammerOrder.func;
	duration = _JammerOrder.duration;
	jammList = _JammerOrder.jammList;
}
void init_JammerOrder(JammerOrder& data) { 
	init_Long(data.orderId);
	init_Long(data.jammerId);
	init_Long(data.func);
	init_Long(data.duration);
	init_JammOperationList(data.jammList);
}
		
// -------------------------------------------------------- JammersOrders
void init_JammersOrders(JammersOrders& data) {}
		
// -------------------------------------------------------- JammerDefinitions
void init_JammerDefinitions(JammerDefinitions& data) {}
		
// -------------------------------------------------------- LocalisationInit
LocalisationInit::LocalisationInit(const LocalisationInit& _LocalisationInit) {
	copy(_LocalisationInit);
}
LocalisationInit& LocalisationInit::operator = (const LocalisationInit& _LocalisationInit) {
	copy(_LocalisationInit);
	return *this;
}
void LocalisationInit::copy(const LocalisationInit& _LocalisationInit) {
	memcpy((void*)pos, (void*)_LocalisationInit.pos, sizeof(Vec3));
	heading = _LocalisationInit.heading;
	mach = _LocalisationInit.mach;
	v = _LocalisationInit.v;
}
void init_LocalisationInit(LocalisationInit& data) { 
	init_Vec3(data.pos);
	init_Real(data.heading);
	init_Real(data.mach);
	init_Real(data.v);
	data.v = 0.;
}
		
// -------------------------------------------------------- LocalisationConst
LocalisationConst::LocalisationConst(const LocalisationConst& _LocalisationConst) {
	copy(_LocalisationConst);
}
LocalisationConst& LocalisationConst::operator = (const LocalisationConst& _LocalisationConst) {
	copy(_LocalisationConst);
	return *this;
}
void LocalisationConst::copy(const LocalisationConst& _LocalisationConst) {
	irs_deriv = _LocalisationConst.irs_deriv;
	ralt_factor = _LocalisationConst.ralt_factor;
	max_dxy_gps = _LocalisationConst.max_dxy_gps;
	max_dz_gps = _LocalisationConst.max_dz_gps;
	max_dxy_ter = _LocalisationConst.max_dxy_ter;
	max_dz_ter = _LocalisationConst.max_dz_ter;
}
void init_LocalisationConst(LocalisationConst& data) { 
	init_Real(data.irs_deriv);
	init_Real(data.ralt_factor);
	init_Real(data.max_dxy_gps);
	init_Real(data.max_dz_gps);
	init_Real(data.max_dxy_ter);
	init_Real(data.max_dz_ter);
}
		
// -------------------------------------------------------- LocalisationState
LocalisationState::LocalisationState(const LocalisationState& _LocalisationState) {
	copy(_LocalisationState);
}
LocalisationState& LocalisationState::operator = (const LocalisationState& _LocalisationState) {
	copy(_LocalisationState);
	return *this;
}
void LocalisationState::copy(const LocalisationState& _LocalisationState) {
	isValid = _LocalisationState.isValid;
	mach = _LocalisationState.mach;
	memcpy((void*)position, (void*)_LocalisationState.position, sizeof(Vec3));
	memcpy((void*)attitudes, (void*)_LocalisationState.attitudes, sizeof(Vec3));
	memcpy((void*)speed, (void*)_LocalisationState.speed, sizeof(Vec3));
	alt_ralt = _LocalisationState.alt_ralt;
}
void init_LocalisationState(LocalisationState& data) { 
	init_Long(data.isValid);
	init_Real(data.mach);
	init_Vec3(data.position);
	init_Vec3(data.attitudes);
	init_Vec3(data.speed);
	init_Real(data.alt_ralt);
}
		
// -------------------------------------------------------- LocalisationError
LocalisationError::LocalisationError(const LocalisationError& _LocalisationError) {
	copy(_LocalisationError);
}
LocalisationError& LocalisationError::operator = (const LocalisationError& _LocalisationError) {
	copy(_LocalisationError);
	return *this;
}
void LocalisationError::copy(const LocalisationError& _LocalisationError) {
	incertitude_dxy = _LocalisationError.incertitude_dxy;
	incertitude_dz = _LocalisationError.incertitude_dz;
	incertitude_ralt = _LocalisationError.incertitude_ralt;
}
void init_LocalisationError(LocalisationError& data) { 
	init_Real(data.incertitude_dxy);
	init_Real(data.incertitude_dz);
	init_Real(data.incertitude_ralt);
}
		
// -------------------------------------------------------- LocalisationEquipmentState
LocalisationEquipmentState::LocalisationEquipmentState(const LocalisationEquipmentState& _LocalisationEquipmentState) {
	copy(_LocalisationEquipmentState);
}
LocalisationEquipmentState& LocalisationEquipmentState::operator = (const LocalisationEquipmentState& _LocalisationEquipmentState) {
	copy(_LocalisationEquipmentState);
	return *this;
}
void LocalisationEquipmentState::copy(const LocalisationEquipmentState& _LocalisationEquipmentState) {
	gps_available = _LocalisationEquipmentState.gps_available;
	irs_available = _LocalisationEquipmentState.irs_available;
	ralt_available = _LocalisationEquipmentState.ralt_available;
	ternum_available = _LocalisationEquipmentState.ternum_available;
}
void init_LocalisationEquipmentState(LocalisationEquipmentState& data) { 
	init_Long(data.gps_available);
	init_Long(data.irs_available);
	init_Long(data.ralt_available);
	init_Long(data.ternum_available);
}
		
// -------------------------------------------------------- LocDefinitions
void init_LocDefinitions(LocDefinitions& data) {}
		
// -------------------------------------------------------- Waypoint
Waypoint::Waypoint(const Waypoint& _Waypoint) {
	copy(_Waypoint);
}
Waypoint& Waypoint::operator = (const Waypoint& _Waypoint) {
	copy(_Waypoint);
	return *this;
}
void Waypoint::copy(const Waypoint& _Waypoint) {
	id = _Waypoint.id;
	g = _Waypoint.g;
	heading = _Waypoint.heading;
	mode = _Waypoint.mode;
	memcpy((void*)position, (void*)_Waypoint.position, sizeof(Vec3));
	pmax = _Waypoint.pmax;
	t = _Waypoint.t;
	dt = _Waypoint.dt;
	v = _Waypoint.v;
	mach = _Waypoint.mach;
	vmin = _Waypoint.vmin;
	vmax = _Waypoint.vmax;
	dv = _Waypoint.dv;
}
void init_Waypoint(Waypoint& data) { 
	init_Long(data.id);
	init_Real(data.g);
	data.g = 2.;
	init_Real(data.heading);
	init_Long(data.mode);
	data.mode = 1;
	init_Vec3(data.position);
	init_Real(data.pmax);
	data.pmax = 10.;
	init_Long(data.t);
	data.t = 0;
	init_Long(data.dt);
	data.dt = 20;
	init_Real(data.v);
	data.v = 0.;
	init_Real(data.mach);
	data.mach = 0.7;
	init_Real(data.vmin);
	data.vmin = 100.;
	init_Real(data.vmax);
	data.vmax = 200.;
	init_Real(data.dv);
	data.dv = 30.;
}
		
// -------------------------------------------------------- NavigationPts
void init_NavigationPts(NavigationPts& data) {}
		
// -------------------------------------------------------- FlightConfig
FlightConfig::FlightConfig(const FlightConfig& _FlightConfig) {
	copy(_FlightConfig);
}
FlightConfig& FlightConfig::operator = (const FlightConfig& _FlightConfig) {
	copy(_FlightConfig);
	return *this;
}
void FlightConfig::copy(const FlightConfig& _FlightConfig) {
	emptyWeight = _FlightConfig.emptyWeight;
	payloadWeight = _FlightConfig.payloadWeight;
	fuelWeight = _FlightConfig.fuelWeight;
	min_speed = _FlightConfig.min_speed;
	max_speed = _FlightConfig.max_speed;
	dv = _FlightConfig.dv;
	dt = _FlightConfig.dt;
	altMin = _FlightConfig.altMin;
	altMax = _FlightConfig.altMax;
}
void init_FlightConfig(FlightConfig& data) { 
	init_Real(data.emptyWeight);
	init_Real(data.payloadWeight);
	init_Real(data.fuelWeight);
	init_Real(data.min_speed);
	init_Real(data.max_speed);
	init_Real(data.dv);
	init_Long(data.dt);
	init_Real(data.altMin);
	init_Real(data.altMax);
}
		
// -------------------------------------------------------- NavigationUpdate
NavigationUpdate::NavigationUpdate(const NavigationUpdate& _NavigationUpdate) {
	copy(_NavigationUpdate);
}
NavigationUpdate& NavigationUpdate::operator = (const NavigationUpdate& _NavigationUpdate) {
	copy(_NavigationUpdate);
	return *this;
}
void NavigationUpdate::copy(const NavigationUpdate& _NavigationUpdate) {
	updated = _NavigationUpdate.updated;
	initialIndex = _NavigationUpdate.initialIndex;
	nav = _NavigationUpdate.nav;
}
void init_NavigationUpdate(NavigationUpdate& data) { 
	init_Long(data.updated);
	init_Long(data.initialIndex);
	init_NavigationPts(data.nav);
}
		
// -------------------------------------------------------- NavigationState
NavigationState::NavigationState(const NavigationState& _NavigationState) {
	copy(_NavigationState);
}
NavigationState& NavigationState::operator = (const NavigationState& _NavigationState) {
	copy(_NavigationState);
	return *this;
}
void NavigationState::copy(const NavigationState& _NavigationState) {
	nav_updated = _NavigationState.nav_updated;
	oldNavIndex = _NavigationState.oldNavIndex;
	navIndex = _NavigationState.navIndex;
	wpId = _NavigationState.wpId;
	distToNextWaypoint = _NavigationState.distToNextWaypoint;
	nav = _NavigationState.nav;
}
void init_NavigationState(NavigationState& data) { 
	init_Long(data.nav_updated);
	init_Long(data.oldNavIndex);
	init_Long(data.navIndex);
	init_Long(data.wpId);
	init_Real(data.distToNextWaypoint);
	init_NavigationPts(data.nav);
}
		
// -------------------------------------------------------- SStateVector
SStateVector::SStateVector(const SStateVector& _SStateVector) {
	copy(_SStateVector);
}
SStateVector& SStateVector::operator = (const SStateVector& _SStateVector) {
	copy(_SStateVector);
	return *this;
}
void SStateVector::copy(const SStateVector& _SStateVector) {
	isValid = _SStateVector.isValid;
	Id = _SStateVector.Id;
	mode = _SStateVector.mode;
	Latitude = _SStateVector.Latitude;
	Longitude = _SStateVector.Longitude;
	Altitude = _SStateVector.Altitude;
	SpeedN = _SStateVector.SpeedN;
	SpeedE = _SStateVector.SpeedE;
	SpeedD = _SStateVector.SpeedD;
	Heading = _SStateVector.Heading;
	Pitch = _SStateVector.Pitch;
	Roll = _SStateVector.Roll;
	Mach = _SStateVector.Mach;
	CAS = _SStateVector.CAS;
	wpID = _SStateVector.wpID;
	wpDist = _SStateVector.wpDist;
}
void init_SStateVector(SStateVector& data) { 
	init_Long(data.isValid);
	init_Long(data.Id);
	init_Long(data.mode);
	init_Real(data.Latitude);
	init_Real(data.Longitude);
	init_Real(data.Altitude);
	init_Real(data.SpeedN);
	init_Real(data.SpeedE);
	init_Real(data.SpeedD);
	init_Real(data.Heading);
	init_Real(data.Pitch);
	init_Real(data.Roll);
	init_Real(data.Mach);
	init_Real(data.CAS);
	init_Long(data.wpID);
	init_Real(data.wpDist);
}
		
// -------------------------------------------------------- SensorTechno
SensorTechno::SensorTechno(const SensorTechno& _SensorTechno) {
	copy(_SensorTechno);
}
SensorTechno& SensorTechno::operator = (const SensorTechno& _SensorTechno) {
	copy(_SensorTechno);
	return *this;
}
void SensorTechno::copy(const SensorTechno& _SensorTechno) {
	id = _SensorTechno.id;
	range = _SensorTechno.range;
}
void init_SensorTechno(SensorTechno& data) { 
	init_Long(data.id);
	init_Real(data.range);
}
		
// -------------------------------------------------------- SensorTechnos
void init_SensorTechnos(SensorTechnos& data) {}
		
// -------------------------------------------------------- SensorDefinition
SensorDefinition::SensorDefinition(const SensorDefinition& _SensorDefinition) {
	copy(_SensorDefinition);
}
SensorDefinition& SensorDefinition::operator = (const SensorDefinition& _SensorDefinition) {
	copy(_SensorDefinition);
	return *this;
}
void SensorDefinition::copy(const SensorDefinition& _SensorDefinition) {
	id = _SensorDefinition.id;
	type = _SensorDefinition.type;
	worksWithEntities = _SensorDefinition.worksWithEntities;
	worksWithEntityTypes = _SensorDefinition.worksWithEntityTypes;
	technos = _SensorDefinition.technos;
	usesLineOfSight = _SensorDefinition.usesLineOfSight;
	fieldOfRegard = _SensorDefinition.fieldOfRegard;
	fieldOfView = _SensorDefinition.fieldOfView;
	intervisiType = _SensorDefinition.intervisiType;
	memcpy((void*)resolution, (void*)_SensorDefinition.resolution, sizeof(Vec3));
	toBeAcquiredDuration = _SensorDefinition.toBeAcquiredDuration;
	toBeLostDuration = _SensorDefinition.toBeLostDuration;
	canBeJammed = _SensorDefinition.canBeJammed;
	historyLenght = _SensorDefinition.historyLenght;
	isEmitter = _SensorDefinition.isEmitter;
}
void init_SensorDefinition(SensorDefinition& data) { 
	init_Long(data.id);
	init_SensorType(data.type);
	init_Long(data.worksWithEntities);
	init_Longs(data.worksWithEntityTypes);
	init_SensorTechnos(data.technos);
	init_Long(data.usesLineOfSight);
	init_SensorAngularBounds(data.fieldOfRegard);
	init_SensorAngularDelta(data.fieldOfView);
	init_Long(data.intervisiType);
	init_Vec3(data.resolution);
	init_Long(data.toBeAcquiredDuration);
	init_Long(data.toBeLostDuration);
	init_Long(data.canBeJammed);
	init_Long(data.historyLenght);
	init_Long(data.isEmitter);
}
		
// -------------------------------------------------------- RadarDefinition
RadarDefinition::RadarDefinition(const RadarDefinition& _RadarDefinition) {
	copy(_RadarDefinition);
}
RadarDefinition& RadarDefinition::operator = (const RadarDefinition& _RadarDefinition) {
	copy(_RadarDefinition);
	return *this;
}
void RadarDefinition::copy(const RadarDefinition& _RadarDefinition) {
	bandID = _RadarDefinition.bandID;
	range = _RadarDefinition.range;
	fov_deltaElevation = _RadarDefinition.fov_deltaElevation;
	fov_deltaAzimut = _RadarDefinition.fov_deltaAzimut;
	for_elevationMin = _RadarDefinition.for_elevationMin;
	for_elevationMax = _RadarDefinition.for_elevationMax;
	for_azimutMin = _RadarDefinition.for_azimutMin;
	for_azimutMax = _RadarDefinition.for_azimutMax;
	toBeAcquiredDuration = _RadarDefinition.toBeAcquiredDuration;
	toBeLostDuration = _RadarDefinition.toBeLostDuration;
}
void init_RadarDefinition(RadarDefinition& data) { 
	init_Long(data.bandID);
	init_Real(data.range);
	init_Real(data.fov_deltaElevation);
	init_Real(data.fov_deltaAzimut);
	init_Real(data.for_elevationMin);
	init_Real(data.for_elevationMax);
	init_Real(data.for_azimutMin);
	init_Real(data.for_azimutMax);
	init_Long(data.toBeAcquiredDuration);
	init_Long(data.toBeLostDuration);
}
		
// -------------------------------------------------------- EsmDefinition
EsmDefinition::EsmDefinition(const EsmDefinition& _EsmDefinition) {
	copy(_EsmDefinition);
}
EsmDefinition& EsmDefinition::operator = (const EsmDefinition& _EsmDefinition) {
	copy(_EsmDefinition);
	return *this;
}
void EsmDefinition::copy(const EsmDefinition& _EsmDefinition) {
	bandID = _EsmDefinition.bandID;
	range = _EsmDefinition.range;
	fov_deltaElevation = _EsmDefinition.fov_deltaElevation;
	fov_deltaAzimut = _EsmDefinition.fov_deltaAzimut;
	for_elevationMin = _EsmDefinition.for_elevationMin;
	for_elevationMax = _EsmDefinition.for_elevationMax;
	for_azimutMin = _EsmDefinition.for_azimutMin;
	for_azimutMax = _EsmDefinition.for_azimutMax;
	toBeAcquiredDuration = _EsmDefinition.toBeAcquiredDuration;
	toBeLostDuration = _EsmDefinition.toBeLostDuration;
}
void init_EsmDefinition(EsmDefinition& data) { 
	init_Long(data.bandID);
	init_Real(data.range);
	init_Real(data.fov_deltaElevation);
	init_Real(data.fov_deltaAzimut);
	init_Real(data.for_elevationMin);
	init_Real(data.for_elevationMax);
	init_Real(data.for_azimutMin);
	init_Real(data.for_azimutMax);
	init_Long(data.toBeAcquiredDuration);
	init_Long(data.toBeLostDuration);
}
		
// -------------------------------------------------------- SensorPlot
SensorPlot::SensorPlot(const SensorPlot& _SensorPlot) {
	copy(_SensorPlot);
}
SensorPlot& SensorPlot::operator = (const SensorPlot& _SensorPlot) {
	copy(_SensorPlot);
	return *this;
}
void SensorPlot::copy(const SensorPlot& _SensorPlot) {
	date = _SensorPlot.date;
	sourceId = _SensorPlot.sourceId;
	sourceType = _SensorPlot.sourceType;
	sourceTechno = _SensorPlot.sourceTechno;
	elevation = _SensorPlot.elevation;
	azimut = _SensorPlot.azimut;
	distance = _SensorPlot.distance;
	memcpy((void*)position, (void*)_SensorPlot.position, sizeof(Vec3));
}
void init_SensorPlot(SensorPlot& data) { 
	init_Long(data.date);
	init_Long(data.sourceId);
	init_SensorType(data.sourceType);
	init_Long(data.sourceTechno);
	init_Real(data.elevation);
	init_Real(data.azimut);
	init_Real(data.distance);
	init_Vec3(data.position);
}
		
// -------------------------------------------------------- SensorImage
SensorImage::SensorImage(const SensorImage& _SensorImage) {
	copy(_SensorImage);
}
SensorImage& SensorImage::operator = (const SensorImage& _SensorImage) {
	copy(_SensorImage);
	return *this;
}
void SensorImage::copy(const SensorImage& _SensorImage) {
	plot = _SensorImage.plot;
	objects = _SensorImage.objects;
}
void init_SensorImage(SensorImage& data) { 
	init_SensorPlot(data.plot);
	init_EntityStates(data.objects);
}
		
// -------------------------------------------------------- SensorImages
void init_SensorImages(SensorImages& data) {}
		
// -------------------------------------------------------- SensorPlotVector
void init_SensorPlotVector(SensorPlotVector& data) {}
		
// -------------------------------------------------------- SensorTrack
SensorTrack::SensorTrack(const SensorTrack& _SensorTrack) {
	copy(_SensorTrack);
}
SensorTrack& SensorTrack::operator = (const SensorTrack& _SensorTrack) {
	copy(_SensorTrack);
	return *this;
}
void SensorTrack::copy(const SensorTrack& _SensorTrack) {
	targetId = _SensorTrack.targetId;
	lastUpdateDate = _SensorTrack.lastUpdateDate;
	plots = _SensorTrack.plots;
	tracked = _SensorTrack.tracked;
	detected = _SensorTrack.detected;
	trackTime = _SensorTrack.trackTime;
	deltaAzimut = _SensorTrack.deltaAzimut;
	deltaElevation = _SensorTrack.deltaElevation;
	doNotFollow = _SensorTrack.doNotFollow;
}
void init_SensorTrack(SensorTrack& data) { 
	init_Long(data.targetId);
	init_Long(data.lastUpdateDate);
	init_SensorPlotVector(data.plots);
	init_Long(data.tracked);
	init_Long(data.detected);
	init_Long(data.trackTime);
	init_Real(data.deltaAzimut);
	init_Real(data.deltaElevation);
	init_Long(data.doNotFollow);
}
		
// -------------------------------------------------------- SensorTracks
void init_SensorTracks(SensorTracks& data) {}
		
// -------------------------------------------------------- SensorStatus
SensorStatus::SensorStatus(const SensorStatus& _SensorStatus) {
	copy(_SensorStatus);
}
SensorStatus& SensorStatus::operator = (const SensorStatus& _SensorStatus) {
	copy(_SensorStatus);
	return *this;
}
void SensorStatus::copy(const SensorStatus& _SensorStatus) {
	lastUpdateDate = _SensorStatus.lastUpdateDate;
	id = _SensorStatus.id;
	type = _SensorStatus.type;
	available = _SensorStatus.available;
	doingOrderId = _SensorStatus.doingOrderId;
	doingOrderDuration = _SensorStatus.doingOrderDuration;
	endOfOrderId = _SensorStatus.endOfOrderId;
	errorFlag = _SensorStatus.errorFlag;
}
void init_SensorStatus(SensorStatus& data) { 
	init_Long(data.lastUpdateDate);
	init_Long(data.id);
	init_SensorType(data.type);
	init_Long(data.available);
	init_Long(data.doingOrderId);
	init_Long(data.doingOrderDuration);
	init_Long(data.endOfOrderId);
	init_Long(data.errorFlag);
}
		
// -------------------------------------------------------- SensorsStatus
void init_SensorsStatus(SensorsStatus& data) {}
		
// -------------------------------------------------------- SensorOrder
SensorOrder::SensorOrder(const SensorOrder& _SensorOrder) {
	copy(_SensorOrder);
}
SensorOrder& SensorOrder::operator = (const SensorOrder& _SensorOrder) {
	copy(_SensorOrder);
	return *this;
}
void SensorOrder::copy(const SensorOrder& _SensorOrder) {
	orderId = _SensorOrder.orderId;
	sensorId = _SensorOrder.sensorId;
	func = _SensorOrder.func;
	fieldOfRegardNbr = _SensorOrder.fieldOfRegardNbr;
	fieldOfViewNbr = _SensorOrder.fieldOfViewNbr;
	lineOfSightElevation = _SensorOrder.lineOfSightElevation;
	lineOfSightAzimut = _SensorOrder.lineOfSightAzimut;
	duration = _SensorOrder.duration;
}
void init_SensorOrder(SensorOrder& data) { 
	init_Long(data.orderId);
	init_Long(data.sensorId);
	init_SensorFunction(data.func);
	init_Long(data.fieldOfRegardNbr);
	init_Long(data.fieldOfViewNbr);
	init_Real(data.lineOfSightElevation);
	init_Real(data.lineOfSightAzimut);
	init_Long(data.duration);
}
		
// -------------------------------------------------------- SensorOrders
void init_SensorOrders(SensorOrders& data) {}
		
// -------------------------------------------------------- SGD
SGD::SGD(const SGD& _SGD) {
	copy(_SGD);
}
SGD& SGD::operator = (const SGD& _SGD) {
	copy(_SGD);
	return *this;
}
void SGD::copy(const SGD& _SGD) {
	hasAB = _SGD.hasAB;
	hasBA = _SGD.hasBA;
	hasBA_RL = _SGD.hasBA_RL;
	hasDist = _SGD.hasDist;
	hasIvisi = _SGD.hasIvisi;
	siteAB = _SGD.siteAB;
	giseAB = _SGD.giseAB;
	siteBA = _SGD.siteBA;
	giseBA = _SGD.giseBA;
	siteBA_RL = _SGD.siteBA_RL;
	giseBA_RL = _SGD.giseBA_RL;
	dist = _SGD.dist;
	ivisi = _SGD.ivisi;
	techno = _SGD.techno;
	range = _SGD.range;
}
void init_SGD(SGD& data) { 
	init_Long(data.hasAB);
	init_Long(data.hasBA);
	init_Long(data.hasBA_RL);
	init_Long(data.hasDist);
	init_Long(data.hasIvisi);
	init_Real(data.siteAB);
	init_Real(data.giseAB);
	init_Real(data.siteBA);
	init_Real(data.giseBA);
	init_Real(data.siteBA_RL);
	init_Real(data.giseBA_RL);
	init_Real(data.dist);
	init_Long(data.ivisi);
	init_Long(data.techno);
	init_Real(data.range);
}
		
// -------------------------------------------------------- SensorMemory
void init_SensorMemory(SensorMemory& data) {}
		
// -------------------------------------------------------- SensorDefinitions
void init_SensorDefinitions(SensorDefinitions& data) {}
		
// -------------------------------------------------------- SAElementStatus
SAElementStatus::SAElementStatus(const SAElementStatus& _SAElementStatus) {
	copy(_SAElementStatus);
}
SAElementStatus& SAElementStatus::operator = (const SAElementStatus& _SAElementStatus) {
	copy(_SAElementStatus);
	return *this;
}
void SAElementStatus::copy(const SAElementStatus& _SAElementStatus) {
	nid = _SAElementStatus.nid;
	type = _SAElementStatus.type;
	doing = _SAElementStatus.doing;
	memcpy((void*)pos, (void*)_SAElementStatus.pos, sizeof(Vec3));
	date = _SAElementStatus.date;
	status = _SAElementStatus.status;
	targetId = _SAElementStatus.targetId;
	munition = _SAElementStatus.munition;
	updated = _SAElementStatus.updated;
}
void init_SAElementStatus(SAElementStatus& data) { 
	init_Long(data.nid);
	data.nid = 0;
	init_Long(data.type);
	data.type = 0;
	init_Long(data.doing);
	data.doing = -1;
	init_Vec3(data.pos);
	init_Long(data.date);
	data.date = 0;
	init_Long(data.status);
	data.status = 0;
	init_Long(data.targetId);
	init_Long(data.munition);
	data.munition = 0;
	init_Long(data.updated);
	data.updated = 0;
}
		
// -------------------------------------------------------- SAElementStatusList
void init_SAElementStatusList(SAElementStatusList& data) {}
		
// -------------------------------------------------------- SAElementOrder
SAElementOrder::SAElementOrder(const SAElementOrder& _SAElementOrder) {
	copy(_SAElementOrder);
}
SAElementOrder& SAElementOrder::operator = (const SAElementOrder& _SAElementOrder) {
	copy(_SAElementOrder);
	return *this;
}
void SAElementOrder::copy(const SAElementOrder& _SAElementOrder) {
	nid = _SAElementOrder.nid;
	orderId = _SAElementOrder.orderId;
	order = _SAElementOrder.order;
	targetId = _SAElementOrder.targetId;
}
void init_SAElementOrder(SAElementOrder& data) { 
	init_Long(data.nid);
	init_Long(data.orderId);
	init_Long(data.order);
	init_Long(data.targetId);
}
		
// -------------------------------------------------------- SAElementOrderList
void init_SAElementOrderList(SAElementOrderList& data) {}
		
// -------------------------------------------------------- SASystemState
SASystemState::SASystemState(const SASystemState& _SASystemState) {
	copy(_SASystemState);
}
SASystemState& SASystemState::operator = (const SASystemState& _SASystemState) {
	copy(_SASystemState);
	return *this;
}
void SASystemState::copy(const SASystemState& _SASystemState) {
	nid = _SASystemState.nid;
	state = _SASystemState.state;
	ordersCount = _SASystemState.ordersCount;
	nbrOfV = _SASystemState.nbrOfV;
	nbrOfCdT = _SASystemState.nbrOfCdT;
	veilles = _SASystemState.veilles;
	cdts = _SASystemState.cdts;
	nbrOfActiveV = _SASystemState.nbrOfActiveV;
	nbrOfActiveCdT = _SASystemState.nbrOfActiveCdT;
}
void init_SASystemState(SASystemState& data) { 
	init_Long(data.nid);
	data.nid = 0;
	init_Long(data.state);
	data.state = 0;
	init_Long(data.ordersCount);
	data.ordersCount = 0;
	init_Long(data.nbrOfV);
	data.nbrOfV = 0;
	init_Long(data.nbrOfCdT);
	data.nbrOfCdT = 0;
	init_Longs(data.veilles);
	init_Longs(data.cdts);
	init_Long(data.nbrOfActiveV);
	data.nbrOfActiveV = 0;
	init_Long(data.nbrOfActiveCdT);
	data.nbrOfActiveCdT = 0;
}
		
// -------------------------------------------------------- FlightData
FlightData::FlightData(const FlightData& _FlightData) {
	copy(_FlightData);
}
FlightData& FlightData::operator = (const FlightData& _FlightData) {
	copy(_FlightData);
	return *this;
}
void FlightData::copy(const FlightData& _FlightData) {
	memcpy((void*)position, (void*)_FlightData.position, sizeof(Vec3));
	memcpy((void*)speed, (void*)_FlightData.speed, sizeof(Vec3));
	memcpy((void*)attitudes, (void*)_FlightData.attitudes, sizeof(Vec3));
	date = _FlightData.date;
}
void init_FlightData(FlightData& data) { 
	init_Vec3(data.position);
	init_Vec3(data.speed);
	init_Vec3(data.attitudes);
	init_Long(data.date);
}
		
// -------------------------------------------------------- NavigationData
NavigationData::NavigationData(const NavigationData& _NavigationData) {
	copy(_NavigationData);
}
NavigationData& NavigationData::operator = (const NavigationData& _NavigationData) {
	copy(_NavigationData);
	return *this;
}
void NavigationData::copy(const NavigationData& _NavigationData) {
	memcpy((void*)position, (void*)_NavigationData.position, sizeof(Vec3));
	memcpy((void*)speed, (void*)_NavigationData.speed, sizeof(Vec3));
	memcpy((void*)attitudes, (void*)_NavigationData.attitudes, sizeof(Vec3));
	date = _NavigationData.date;
	wpId = _NavigationData.wpId;
	distToNextWaypoint = _NavigationData.distToNextWaypoint;
	nav = _NavigationData.nav;
}
void init_NavigationData(NavigationData& data) { 
	init_Vec3(data.position);
	init_Vec3(data.speed);
	init_Vec3(data.attitudes);
	init_Long(data.date);
	init_Long(data.wpId);
	init_Real(data.distToNextWaypoint);
	init_NavigationPts(data.nav);
}
		
// -------------------------------------------------------- NetworkDefinition
NetworkDefinition::NetworkDefinition(const NetworkDefinition& _NetworkDefinition) {
	copy(_NetworkDefinition);
}
NetworkDefinition& NetworkDefinition::operator = (const NetworkDefinition& _NetworkDefinition) {
	copy(_NetworkDefinition);
	return *this;
}
void NetworkDefinition::copy(const NetworkDefinition& _NetworkDefinition) {
	name = _NetworkDefinition.name;
	id = _NetworkDefinition.id;
	isBLOS = _NetworkDefinition.isBLOS;
	maxDist = _NetworkDefinition.maxDist;
	networkBandwidth = _NetworkDefinition.networkBandwidth;
	maxSendConnectionPerAccess = _NetworkDefinition.maxSendConnectionPerAccess;
	maxRcvConnectionPerAccess = _NetworkDefinition.maxRcvConnectionPerAccess;
	maxSendBandwidthPerConnection = _NetworkDefinition.maxSendBandwidthPerConnection;
	maxRcvBandwidthPerAccess = _NetworkDefinition.maxRcvBandwidthPerAccess;
	maxConnectionInNetwork = _NetworkDefinition.maxConnectionInNetwork;
	maxNumberOfAccess = _NetworkDefinition.maxNumberOfAccess;
}
void init_NetworkDefinition(NetworkDefinition& data) { 
	init_String(data.name);
	init_Long(data.id);
	init_Long(data.isBLOS);
	init_Real(data.maxDist);
	init_Real(data.networkBandwidth);
	init_Long(data.maxSendConnectionPerAccess);
	init_Long(data.maxRcvConnectionPerAccess);
	init_Real(data.maxSendBandwidthPerConnection);
	init_Real(data.maxRcvBandwidthPerAccess);
	init_Long(data.maxConnectionInNetwork);
	init_Long(data.maxNumberOfAccess);
}
		
// -------------------------------------------------------- NetworkMessagePrivateHeader
NetworkMessagePrivateHeader::NetworkMessagePrivateHeader(const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader) {
	copy(_NetworkMessagePrivateHeader);
}
NetworkMessagePrivateHeader& NetworkMessagePrivateHeader::operator = (const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader) {
	copy(_NetworkMessagePrivateHeader);
	return *this;
}
void NetworkMessagePrivateHeader::copy(const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader) {
	timestamp = _NetworkMessagePrivateHeader.timestamp;
	sizeTransmitted = _NetworkMessagePrivateHeader.sizeTransmitted;
}
void init_NetworkMessagePrivateHeader(NetworkMessagePrivateHeader& data) { 
	init_Long(data.timestamp);
	init_Real(data.sizeTransmitted);
}
		
// -------------------------------------------------------- NetworkMessageUserHeader
NetworkMessageUserHeader::NetworkMessageUserHeader(const NetworkMessageUserHeader& _NetworkMessageUserHeader) {
	copy(_NetworkMessageUserHeader);
}
NetworkMessageUserHeader& NetworkMessageUserHeader::operator = (const NetworkMessageUserHeader& _NetworkMessageUserHeader) {
	copy(_NetworkMessageUserHeader);
	return *this;
}
void NetworkMessageUserHeader::copy(const NetworkMessageUserHeader& _NetworkMessageUserHeader) {
	networkId = _NetworkMessageUserHeader.networkId;
	fromId = _NetworkMessageUserHeader.fromId;
	toId = _NetworkMessageUserHeader.toId;
	networkMsgId = _NetworkMessageUserHeader.networkMsgId;
	dataSize = _NetworkMessageUserHeader.dataSize;
	category = _NetworkMessageUserHeader.category;
}
void init_NetworkMessageUserHeader(NetworkMessageUserHeader& data) { 
	init_NetworkID(data.networkId);
	init_Long(data.fromId);
	init_Long(data.toId);
	init_Long(data.networkMsgId);
	init_Long(data.dataSize);
	init_Long(data.category);
}
		
// -------------------------------------------------------- NetworkMessageUserData
NetworkMessageUserData::NetworkMessageUserData() {}
const unsigned int NetworkMessageUserData::__FlightData = 1; 
void NetworkMessageUserData::set_FlightData(const FlightData& d) {
	_FlightData_ = d;
	type = __FlightData;
}
const FlightData* NetworkMessageUserData::get_FlightData() {
	if (type==__FlightData) return &(_FlightData_);
	else { cerr << "NetworkMessageUserData, bad type asked !" << endl; return NULL; }
}
const unsigned int NetworkMessageUserData::__NavigationData = 2; 
void NetworkMessageUserData::set_NavigationData(const NavigationData& d) {
	_NavigationData_ = d;
	type = __NavigationData;
}
const NavigationData* NetworkMessageUserData::get_NavigationData() {
	if (type==__NavigationData) return &(_NavigationData_);
	else { cerr << "NetworkMessageUserData, bad type asked !" << endl; return NULL; }
}
NetworkMessageUserData::NetworkMessageUserData(const NetworkMessageUserData& u) {
	type=u.type;
	if (type==__FlightData) _FlightData_ =  u._FlightData_;
	if (type==__NavigationData) _NavigationData_ =  u._NavigationData_;
}
NetworkMessageUserData::~NetworkMessageUserData() {  type = 0; }
NetworkMessageUserData& NetworkMessageUserData::operator = (const NetworkMessageUserData& u) {
	type=u.type;
	if (type==__FlightData) _FlightData_ =  u._FlightData_;
	if (type==__NavigationData) _NavigationData_ =  u._NavigationData_;
	return *this;
}
void init_NetworkMessageUserData(NetworkMessageUserData& data) { }
		
// -------------------------------------------------------- NetworkMessage
NetworkMessage::NetworkMessage(const NetworkMessage& _NetworkMessage) {
	copy(_NetworkMessage);
}
NetworkMessage& NetworkMessage::operator = (const NetworkMessage& _NetworkMessage) {
	copy(_NetworkMessage);
	return *this;
}
void NetworkMessage::copy(const NetworkMessage& _NetworkMessage) {
	uheader = _NetworkMessage.uheader;
	pheader = _NetworkMessage.pheader;
	data = _NetworkMessage.data;
}
void init_NetworkMessage(NetworkMessage& data) { 
	init_NetworkMessageUserHeader(data.uheader);
	init_NetworkMessagePrivateHeader(data.pheader);
	init_NetworkMessageUserData(data.data);
}
		
// -------------------------------------------------------- NetworkMessageDeliveryReport
void init_NetworkMessageDeliveryReport(NetworkMessageDeliveryReport& data) {}
		
// -------------------------------------------------------- NetworkMessageDeliveryReports
void init_NetworkMessageDeliveryReports(NetworkMessageDeliveryReports& data) {}
		
// -------------------------------------------------------- NetworkList
void init_NetworkList(NetworkList& data) {}
		
// -------------------------------------------------------- NetworkMessageList
void init_NetworkMessageList(NetworkMessageList& data) {}
		
// -------------------------------------------------------- NetworkDefinitions
void init_NetworkDefinitions(NetworkDefinitions& data) {}
		
// -------------------------------------------------------- test
test::test(const test& _test) {
	copy(_test);
}
test& test::operator = (const test& _test) {
	copy(_test);
	return *this;
}
void test::copy(const test& _test) {
	fromId = _test.fromId;
	toId = _test.toId;
}
void init_test(test& data) { 
	init_Long(data.fromId);
	init_Long(data.toId);
}
		
// -------------------------------------------------------- TestMatlabStruct2
TestMatlabStruct2::TestMatlabStruct2(const TestMatlabStruct2& _TestMatlabStruct2) {
	copy(_TestMatlabStruct2);
}
TestMatlabStruct2& TestMatlabStruct2::operator = (const TestMatlabStruct2& _TestMatlabStruct2) {
	copy(_TestMatlabStruct2);
	return *this;
}
void TestMatlabStruct2::copy(const TestMatlabStruct2& _TestMatlabStruct2) {
	i = _TestMatlabStruct2.i;
	j = _TestMatlabStruct2.j;
	x = _TestMatlabStruct2.x;
}
void init_TestMatlabStruct2(TestMatlabStruct2& data) { 
	init_Long(data.i);
	init_Long(data.j);
	init_Real(data.x);
}
		
// -------------------------------------------------------- TestMatlabStruct2List
void init_TestMatlabStruct2List(TestMatlabStruct2List& data) {}
		
// -------------------------------------------------------- TestMatlabStruct
TestMatlabStruct::TestMatlabStruct(const TestMatlabStruct& _TestMatlabStruct) {
	copy(_TestMatlabStruct);
}
TestMatlabStruct& TestMatlabStruct::operator = (const TestMatlabStruct& _TestMatlabStruct) {
	copy(_TestMatlabStruct);
	return *this;
}
void TestMatlabStruct::copy(const TestMatlabStruct& _TestMatlabStruct) {
	unLong = _TestMatlabStruct.unLong;
	unReal = _TestMatlabStruct.unReal;
	memcpy((void*)unVec3, (void*)_TestMatlabStruct.unVec3, sizeof(Vec3));
	unVecteurDeLongs = _TestMatlabStruct.unVecteurDeLongs;
	uneListe = _TestMatlabStruct.uneListe;
}
void init_TestMatlabStruct(TestMatlabStruct& data) { 
	init_Long(data.unLong);
	init_Real(data.unReal);
	init_Vec3(data.unVec3);
	init_Longs(data.unVecteurDeLongs);
	init_TestMatlabStruct2List(data.uneListe);
}
		
// -------------------------------------------------------- TestJavaStruct2
TestJavaStruct2::TestJavaStruct2(const TestJavaStruct2& _TestJavaStruct2) {
	copy(_TestJavaStruct2);
}
TestJavaStruct2& TestJavaStruct2::operator = (const TestJavaStruct2& _TestJavaStruct2) {
	copy(_TestJavaStruct2);
	return *this;
}
void TestJavaStruct2::copy(const TestJavaStruct2& _TestJavaStruct2) {
	i = _TestJavaStruct2.i;
	j = _TestJavaStruct2.j;
	x = _TestJavaStruct2.x;
}
void init_TestJavaStruct2(TestJavaStruct2& data) { 
	init_Long(data.i);
	init_Long(data.j);
	init_Real(data.x);
}
		
// -------------------------------------------------------- TestJavaStruct2List
void init_TestJavaStruct2List(TestJavaStruct2List& data) {}
		
// -------------------------------------------------------- TestJavaStruct
TestJavaStruct::TestJavaStruct(const TestJavaStruct& _TestJavaStruct) {
	copy(_TestJavaStruct);
}
TestJavaStruct& TestJavaStruct::operator = (const TestJavaStruct& _TestJavaStruct) {
	copy(_TestJavaStruct);
	return *this;
}
void TestJavaStruct::copy(const TestJavaStruct& _TestJavaStruct) {
	unLong = _TestJavaStruct.unLong;
	unReal = _TestJavaStruct.unReal;
	memcpy((void*)unVec3, (void*)_TestJavaStruct.unVec3, sizeof(Vec3));
	memcpy((void*)unVecX->data(), (void*)_TestJavaStruct.unVecX->data(), unVecX->num_elements()*sizeof(Real));	
	unVecteurDeLongs = _TestJavaStruct.unVecteurDeLongs;
	uneListe = _TestJavaStruct.uneListe;
}
void init_TestJavaStruct(TestJavaStruct& data) { 
	init_Long(data.unLong);
	init_Real(data.unReal);
	init_Vec3(data.unVec3);
	init_VecX(data.unVecX);
	init_Longs(data.unVecteurDeLongs);
	init_TestMatlabStruct2List(data.uneListe);
}
		

// 
// ------------------------------------------------------------------------------------
//

} // eof namespace generated

