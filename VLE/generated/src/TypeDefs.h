
#ifndef _TypeDefs_h_
#define _TypeDefs_h_

// 
// Includes ----------------------------------------------------------------------
// 

#include <iostream>
#include <vector>
#include <map>
#include <boost/multi_array.hpp>
#include <string>							


//
namespace generated 
{

//
// Data type definitions ----------------------------------------------------------
//

// -------------------------------------------------------- Pointer
// basic type Pointer	
typedef void* Pointer;
void init_Pointer(Pointer& data);
		
// -------------------------------------------------------- String
// basic type String	
typedef std::string String;
void init_String(String& data);
		
// -------------------------------------------------------- Logical
// basic type Logical	
typedef bool Logical;
void init_Logical(Logical& data);
		
// -------------------------------------------------------- Int
// basic type Int	
typedef int Int;
void init_Int(Int& data);
		
// -------------------------------------------------------- Long
// basic type Long	
typedef long Long;
void init_Long(Long& data);
		
// -------------------------------------------------------- Real
// basic type Real	
typedef double Real;
void init_Real(Real& data);
		
// -------------------------------------------------------- Vec3
// Vec3 is an array of Real
typedef Real Vec3[3];	
void init_Vec3(Vec3& data);
		
// -------------------------------------------------------- Vec5
// Vec5 is an array of Real
typedef Real Vec5[5];	
void init_Vec5(Vec5& data);
		
// -------------------------------------------------------- VecX
// VecX is an array of Real
typedef boost::multi_array<Real, 2>* VecX;
VecX VecX_allocate(unsigned int x, unsigned int y);	
void init_VecX(VecX& data);
		
// -------------------------------------------------------- gisement
// gisement is a Real
typedef Real gisement;
void init_gisement(gisement& data);
		
// -------------------------------------------------------- site
// site is a Real
typedef Real site;
void init_site(site& data);
		
// -------------------------------------------------------- VecOne
// VecOne is an array of gisement
typedef boost::multi_array<gisement, 1>* VecOne;
VecOne VecOne_allocate(unsigned int x);	
void init_VecOne(VecOne& data);
		
// -------------------------------------------------------- VecY
// VecY is an array of gisement
typedef gisement VecY[3];	
void init_VecY(VecY& data);
		
// -------------------------------------------------------- test3
// test3 is a structure
class test3 {
public:
	Real hello;
	gisement g;
	test3() { }
	test3(const test3& _test3);
	test3& operator = (const test3& _test3);
	void copy(const test3& _test3);
} ;
void init_test3(test3& data);
		
// -------------------------------------------------------- Ints
// Ints is a vector of Int
typedef std::vector<Int> Ints ;
void init_Ints(Ints& data);
		
// -------------------------------------------------------- Longs
// Longs is a vector of Long
typedef std::vector<Long> Longs ;
void init_Longs(Longs& data);
		
// -------------------------------------------------------- Reals
// Reals is a vector of Real
typedef std::vector<Real> Reals ;
void init_Reals(Reals& data);
		
// -------------------------------------------------------- EntityType
// basic type EntityType	
typedef enum { ABSTRACT_ENTITY=0, AIR=0, GROUND=1, SUB=4, SPACE=5 } EntityType;
void init_EntityType(EntityType& data);
		
// -------------------------------------------------------- NetworkID
// basic type NetworkID	
typedef enum { INVALID_NETWORK=0, IFDL=20001, LBWDL=20002, HBWDL=20003, TCAS=20004 } NetworkID;
void init_NetworkID(NetworkID& data);
		
// -------------------------------------------------------- SensorType
// basic type SensorType	
typedef enum { INVALID_SENSOR_TYPE=0, MAW = 1, ESM = 2, RDR = 3, SAR = 4, EOIR = 5 } SensorType;
void init_SensorType(SensorType& data);
		
// -------------------------------------------------------- SensorFunction
// basic type SensorFunction	
typedef enum { INVALID_SENSOR_FUNCTION=0,  IMAGE = 1, SEQUENCE_OF_IMAGE = 2, SEARCH_AND_TRACK = 3} SensorFunction;
void init_SensorFunction(SensorFunction& data);
		
// -------------------------------------------------------- EquipmentType
// basic type EquipmentType	
typedef enum { PLATFORM=0, EQP_COMMS=1 } EquipmentType;
void init_EquipmentType(EquipmentType& data);
		
// -------------------------------------------------------- EquipmentStatus
// EquipmentStatus is a structure
class EquipmentStatus {
public:
	Long type;
	Long id;
	Long available;
	Long enabled;
	EquipmentStatus() { }
	EquipmentStatus(const EquipmentStatus& _EquipmentStatus);
	EquipmentStatus& operator = (const EquipmentStatus& _EquipmentStatus);
	void copy(const EquipmentStatus& _EquipmentStatus);
} ;
void init_EquipmentStatus(EquipmentStatus& data);
		
// -------------------------------------------------------- EquipmentStatusList
// EquipmentStatusList is a map with key type Long and value type EquipmentStatus
typedef std::map <Long, EquipmentStatus> EquipmentStatusList;
void init_EquipmentStatusList(EquipmentStatusList& data);
		
// -------------------------------------------------------- ExternalInput
// ExternalInput is a structure
class ExternalInput {
public:
	Long id;
	Long duration;
	Long available_during;
	Long available_after;
	ExternalInput() { }
	ExternalInput(const ExternalInput& _ExternalInput);
	ExternalInput& operator = (const ExternalInput& _ExternalInput);
	void copy(const ExternalInput& _ExternalInput);
} ;
void init_ExternalInput(ExternalInput& data);
		
// -------------------------------------------------------- vExternalInput
// vExternalInput is a vector of ExternalInput
typedef std::vector<ExternalInput> vExternalInput ;
void init_vExternalInput(vExternalInput& data);
		
// -------------------------------------------------------- ExternalInputListForOneTypeOfEquipment
// ExternalInputListForOneTypeOfEquipment is a map with key type EquipmentType and value type vExternalInput
typedef std::map <EquipmentType, vExternalInput> ExternalInputListForOneTypeOfEquipment;
void init_ExternalInputListForOneTypeOfEquipment(ExternalInputListForOneTypeOfEquipment& data);
		
// -------------------------------------------------------- ExternalInputList
// ExternalInputList is a map with key type Long and value type ExternalInputListForOneTypeOfEquipment
typedef std::map <Long, ExternalInputListForOneTypeOfEquipment> ExternalInputList;
void init_ExternalInputList(ExternalInputList& data);
		
// -------------------------------------------------------- EntityState
// EntityState is a structure
class EntityState {
public:
	Long time;
	Long id;
	Long side;
	EntityType type;
	Long subtype;
	Long subsubtype;
	Vec3 position;
	Vec3 speed;
	Vec3 attitudes;
	EntityState() { }
	EntityState(const EntityState& _EntityState);
	EntityState& operator = (const EntityState& _EntityState);
	void copy(const EntityState& _EntityState);
} ;
void init_EntityState(EntityState& data);
		
// -------------------------------------------------------- EntityStates
// EntityStates is a map with key type Long and value type EntityState
typedef std::map <Long, EntityState> EntityStates;
void init_EntityStates(EntityStates& data);
		
// -------------------------------------------------------- EmitterBeam
// EmitterBeam is a structure
class EmitterBeam {
public:
	Real elevation;
	Real azimut;
	Real elevationAperture;
	Real azimutAperture;
	Longs targets;
	EmitterBeam() { }
	EmitterBeam(const EmitterBeam& _EmitterBeam);
	EmitterBeam& operator = (const EmitterBeam& _EmitterBeam);
	void copy(const EmitterBeam& _EmitterBeam);
} ;
void init_EmitterBeam(EmitterBeam& data);
		
// -------------------------------------------------------- Beams
// Beams is a vector of EmitterBeam
typedef std::vector<EmitterBeam> Beams ;
void init_Beams(Beams& data);
		
// -------------------------------------------------------- EmitterState
// EmitterState is a structure
class EmitterState {
public:
	Long time;
	Long entityID;
	SensorType type;
	Long techno;
	Real dist1m2;
	Beams beams;
	EmitterState() { }
	EmitterState(const EmitterState& _EmitterState);
	EmitterState& operator = (const EmitterState& _EmitterState);
	void copy(const EmitterState& _EmitterState);
} ;
void init_EmitterState(EmitterState& data);
		
// -------------------------------------------------------- EmitterStates
// EmitterStates is a vector of EmitterState
typedef std::vector<EmitterState> EmitterStates ;
void init_EmitterStates(EmitterStates& data);
		
// -------------------------------------------------------- JammerState
// JammerState is a structure
class JammerState {
public:
	Long time;
	Long entityID;
	Long type;
	Long techno;
	Real elevation;
	Real azimut;
	Real apertureEl;
	Real apertureAz;
	Real powerOrDistance;
	JammerState() { }
	JammerState(const JammerState& _JammerState);
	JammerState& operator = (const JammerState& _JammerState);
	void copy(const JammerState& _JammerState);
} ;
void init_JammerState(JammerState& data);
		
// -------------------------------------------------------- JammerStates
// JammerStates is a vector of JammerState
typedef std::vector<JammerState> JammerStates ;
void init_JammerStates(JammerStates& data);
		
// -------------------------------------------------------- Detonation
// Detonation is a structure
class Detonation {
public:
	Long time;
	Long shooterID;
	Long weaponType;
	Longs targets;
	Vec3 position;
	Detonation() { }
	Detonation(const Detonation& _Detonation);
	Detonation& operator = (const Detonation& _Detonation);
	void copy(const Detonation& _Detonation);
} ;
void init_Detonation(Detonation& data);
		
// -------------------------------------------------------- Detonations
// Detonations is a map with key type Long and value type Detonation
typedef std::map <Long, Detonation> Detonations;
void init_Detonations(Detonations& data);
		
// -------------------------------------------------------- EnvironmentInteractions
// EnvironmentInteractions is a structure
class EnvironmentInteractions {
public:
	EntityStates entities;
	EmitterStates emitters;
	JammerStates jammers;
	Detonations detonations;
	EnvironmentInteractions() { }
	EnvironmentInteractions(const EnvironmentInteractions& _EnvironmentInteractions);
	EnvironmentInteractions& operator = (const EnvironmentInteractions& _EnvironmentInteractions);
	void copy(const EnvironmentInteractions& _EnvironmentInteractions);
} ;
void init_EnvironmentInteractions(EnvironmentInteractions& data);
		
// -------------------------------------------------------- AngularBounds
// AngularBounds is a structure
class AngularBounds {
public:
	Long symetric;
	Real elevationMin;
	Real elevationMax;
	Real azimutMin;
	Real azimutMax;
	AngularBounds() { }
	AngularBounds(const AngularBounds& _AngularBounds);
	AngularBounds& operator = (const AngularBounds& _AngularBounds);
	void copy(const AngularBounds& _AngularBounds);
} ;
void init_AngularBounds(AngularBounds& data);
		
// -------------------------------------------------------- AngularDelta
// AngularDelta is a structure
class AngularDelta {
public:
	Real deltaElevation;
	Real deltaAzimut;
	AngularDelta() { }
	AngularDelta(const AngularDelta& _AngularDelta);
	AngularDelta& operator = (const AngularDelta& _AngularDelta);
	void copy(const AngularDelta& _AngularDelta);
} ;
void init_AngularDelta(AngularDelta& data);
		
// -------------------------------------------------------- SensorAngularBounds
// SensorAngularBounds is a vector of AngularBounds
typedef std::vector<AngularBounds> SensorAngularBounds ;
void init_SensorAngularBounds(SensorAngularBounds& data);
		
// -------------------------------------------------------- SensorAngularDelta
// SensorAngularDelta is a vector of AngularDelta
typedef std::vector<AngularDelta> SensorAngularDelta ;
void init_SensorAngularDelta(SensorAngularDelta& data);
		
// -------------------------------------------------------- JammerDefinition
// JammerDefinition is a structure
class JammerDefinition {
public:
	Long id;
	Long domainId;
	Long type;
	Long techno;
	Real maxPowerAllocation;
	AngularBounds bounds;
	Long maxTargetNumber;
	Real apertureEl;
	Real apertureAz;
	JammerDefinition() { }
	JammerDefinition(const JammerDefinition& _JammerDefinition);
	JammerDefinition& operator = (const JammerDefinition& _JammerDefinition);
	void copy(const JammerDefinition& _JammerDefinition);
} ;
void init_JammerDefinition(JammerDefinition& data);
		
// -------------------------------------------------------- EmitterJammed
// EmitterJammed is a structure
class EmitterJammed {
public:
	Long entityID;
	Real powerAllocation;
	EmitterJammed() { }
	EmitterJammed(const EmitterJammed& _EmitterJammed);
	EmitterJammed& operator = (const EmitterJammed& _EmitterJammed);
	void copy(const EmitterJammed& _EmitterJammed);
} ;
void init_EmitterJammed(EmitterJammed& data);
		
// -------------------------------------------------------- EmitterJammList
// EmitterJammList is a vector of EmitterJammed
typedef std::vector<EmitterJammed> EmitterJammList ;
void init_EmitterJammList(EmitterJammList& data);
		
// -------------------------------------------------------- JammerStatus
// JammerStatus is a structure
class JammerStatus {
public:
	Long lastUpdateDate;
	Long id;
	Long type;
	Long techno;
	Long available;
	Long endOfOrderId;
	Long doingOrderId;
	Long doingOrderDuration;
	Long errorFlag;
	Long nbrOfJammOps;
	JammerStatus() { }
	JammerStatus(const JammerStatus& _JammerStatus);
	JammerStatus& operator = (const JammerStatus& _JammerStatus);
	void copy(const JammerStatus& _JammerStatus);
} ;
void init_JammerStatus(JammerStatus& data);
		
// -------------------------------------------------------- JammersStatus
// JammersStatus is a map with key type Long and value type JammerStatus
typedef std::map <Long, JammerStatus> JammersStatus;
void init_JammersStatus(JammersStatus& data);
		
// -------------------------------------------------------- JammOp
// JammOp is a structure
class JammOp {
public:
	Long target_id;
	Real azimut;
	Real elevation;
	JammOp() { }
	JammOp(const JammOp& _JammOp);
	JammOp& operator = (const JammOp& _JammOp);
	void copy(const JammOp& _JammOp);
} ;
void init_JammOp(JammOp& data);
		
// -------------------------------------------------------- JammOperationList
// JammOperationList is a vector of JammOp
typedef std::vector<JammOp> JammOperationList ;
void init_JammOperationList(JammOperationList& data);
		
// -------------------------------------------------------- JammerOrder
// JammerOrder is a structure
class JammerOrder {
public:
	Long orderId;
	Long jammerId;
	Long func;
	Long duration;
	JammOperationList jammList;
	JammerOrder() { }
	JammerOrder(const JammerOrder& _JammerOrder);
	JammerOrder& operator = (const JammerOrder& _JammerOrder);
	void copy(const JammerOrder& _JammerOrder);
} ;
void init_JammerOrder(JammerOrder& data);
		
// -------------------------------------------------------- JammersOrders
// JammersOrders is a map with key type Long and value type JammerOrder
typedef std::map <Long, JammerOrder> JammersOrders;
void init_JammersOrders(JammersOrders& data);
		
// -------------------------------------------------------- JammerDefinitions
// JammerDefinitions is a map with key type Long and value type JammerDefinition
typedef std::map <Long, JammerDefinition> JammerDefinitions;
void init_JammerDefinitions(JammerDefinitions& data);
		
// -------------------------------------------------------- LocalisationInit
// LocalisationInit is a structure
class LocalisationInit {
public:
	Vec3 pos;
	Real heading;
	Real mach;
	Real v;
	LocalisationInit() { }
	LocalisationInit(const LocalisationInit& _LocalisationInit);
	LocalisationInit& operator = (const LocalisationInit& _LocalisationInit);
	void copy(const LocalisationInit& _LocalisationInit);
} ;
void init_LocalisationInit(LocalisationInit& data);
		
// -------------------------------------------------------- LocalisationConst
// LocalisationConst is a structure
class LocalisationConst {
public:
	Real irs_deriv;
	Real ralt_factor;
	Real max_dxy_gps;
	Real max_dz_gps;
	Real max_dxy_ter;
	Real max_dz_ter;
	LocalisationConst() { }
	LocalisationConst(const LocalisationConst& _LocalisationConst);
	LocalisationConst& operator = (const LocalisationConst& _LocalisationConst);
	void copy(const LocalisationConst& _LocalisationConst);
} ;
void init_LocalisationConst(LocalisationConst& data);
		
// -------------------------------------------------------- LocalisationState
// LocalisationState is a structure
class LocalisationState {
public:
	Long isValid;
	Real mach;
	Vec3 position;
	Vec3 attitudes;
	Vec3 speed;
	Real alt_ralt;
	LocalisationState() { }
	LocalisationState(const LocalisationState& _LocalisationState);
	LocalisationState& operator = (const LocalisationState& _LocalisationState);
	void copy(const LocalisationState& _LocalisationState);
} ;
void init_LocalisationState(LocalisationState& data);
		
// -------------------------------------------------------- LocalisationError
// LocalisationError is a structure
class LocalisationError {
public:
	Real incertitude_dxy;
	Real incertitude_dz;
	Real incertitude_ralt;
	LocalisationError() { }
	LocalisationError(const LocalisationError& _LocalisationError);
	LocalisationError& operator = (const LocalisationError& _LocalisationError);
	void copy(const LocalisationError& _LocalisationError);
} ;
void init_LocalisationError(LocalisationError& data);
		
// -------------------------------------------------------- LocalisationEquipmentState
// LocalisationEquipmentState is a structure
class LocalisationEquipmentState {
public:
	Long gps_available;
	Long irs_available;
	Long ralt_available;
	Long ternum_available;
	LocalisationEquipmentState() { }
	LocalisationEquipmentState(const LocalisationEquipmentState& _LocalisationEquipmentState);
	LocalisationEquipmentState& operator = (const LocalisationEquipmentState& _LocalisationEquipmentState);
	void copy(const LocalisationEquipmentState& _LocalisationEquipmentState);
} ;
void init_LocalisationEquipmentState(LocalisationEquipmentState& data);
		
// -------------------------------------------------------- LocDefinitions
// LocDefinitions is a map with key type Long and value type LocalisationConst
typedef std::map <Long, LocalisationConst> LocDefinitions;
void init_LocDefinitions(LocDefinitions& data);
		
// -------------------------------------------------------- Waypoint
// Waypoint is a structure
class Waypoint {
public:
	Long id;
	Real g;
	Real heading;
	Long mode;
	Vec3 position;
	Real pmax;
	Long t;
	Long dt;
	Real v;
	Real mach;
	Real vmin;
	Real vmax;
	Real dv;
	Waypoint() { }
	Waypoint(const Waypoint& _Waypoint);
	Waypoint& operator = (const Waypoint& _Waypoint);
	void copy(const Waypoint& _Waypoint);
} ;
void init_Waypoint(Waypoint& data);
		
// -------------------------------------------------------- NavigationPts
// NavigationPts is a vector of Waypoint
typedef std::vector<Waypoint> NavigationPts ;
void init_NavigationPts(NavigationPts& data);
		
// -------------------------------------------------------- FlightConfig
// FlightConfig is a structure
class FlightConfig {
public:
	Real emptyWeight;
	Real payloadWeight;
	Real fuelWeight;
	Real min_speed;
	Real max_speed;
	Real dv;
	Long dt;
	Real altMin;
	Real altMax;
	FlightConfig() { }
	FlightConfig(const FlightConfig& _FlightConfig);
	FlightConfig& operator = (const FlightConfig& _FlightConfig);
	void copy(const FlightConfig& _FlightConfig);
} ;
void init_FlightConfig(FlightConfig& data);
		
// -------------------------------------------------------- NavigationUpdate
// NavigationUpdate is a structure
class NavigationUpdate {
public:
	Long updated;
	Long initialIndex;
	NavigationPts nav;
	NavigationUpdate() { }
	NavigationUpdate(const NavigationUpdate& _NavigationUpdate);
	NavigationUpdate& operator = (const NavigationUpdate& _NavigationUpdate);
	void copy(const NavigationUpdate& _NavigationUpdate);
} ;
void init_NavigationUpdate(NavigationUpdate& data);
		
// -------------------------------------------------------- NavigationState
// NavigationState is a structure
class NavigationState {
public:
	Long nav_updated;
	Long oldNavIndex;
	Long navIndex;
	Long wpId;
	Real distToNextWaypoint;
	NavigationPts nav;
	NavigationState() { }
	NavigationState(const NavigationState& _NavigationState);
	NavigationState& operator = (const NavigationState& _NavigationState);
	void copy(const NavigationState& _NavigationState);
} ;
void init_NavigationState(NavigationState& data);
		
// -------------------------------------------------------- SStateVector
// SStateVector is a structure
class SStateVector {
public:
	Long isValid;
	Long Id;
	Long mode;
	Real Latitude;
	Real Longitude;
	Real Altitude;
	Real SpeedN;
	Real SpeedE;
	Real SpeedD;
	Real Heading;
	Real Pitch;
	Real Roll;
	Real Mach;
	Real CAS;
	Long wpID;
	Real wpDist;
	SStateVector() { }
	SStateVector(const SStateVector& _SStateVector);
	SStateVector& operator = (const SStateVector& _SStateVector);
	void copy(const SStateVector& _SStateVector);
} ;
void init_SStateVector(SStateVector& data);
		
// -------------------------------------------------------- SensorTechno
// SensorTechno is a structure
class SensorTechno {
public:
	Long id;
	Real range;
	SensorTechno() { }
	SensorTechno(const SensorTechno& _SensorTechno);
	SensorTechno& operator = (const SensorTechno& _SensorTechno);
	void copy(const SensorTechno& _SensorTechno);
} ;
void init_SensorTechno(SensorTechno& data);
		
// -------------------------------------------------------- SensorTechnos
// SensorTechnos is a vector of SensorTechno
typedef std::vector<SensorTechno> SensorTechnos ;
void init_SensorTechnos(SensorTechnos& data);
		
// -------------------------------------------------------- SensorDefinition
// SensorDefinition is a structure
class SensorDefinition {
public:
	Long id;
	SensorType type;
	Long worksWithEntities;
	Longs worksWithEntityTypes;
	SensorTechnos technos;
	Long usesLineOfSight;
	SensorAngularBounds fieldOfRegard;
	SensorAngularDelta fieldOfView;
	Long intervisiType;
	Vec3 resolution;
	Long toBeAcquiredDuration;
	Long toBeLostDuration;
	Long canBeJammed;
	Long historyLenght;
	Long isEmitter;
	SensorDefinition() { }
	SensorDefinition(const SensorDefinition& _SensorDefinition);
	SensorDefinition& operator = (const SensorDefinition& _SensorDefinition);
	void copy(const SensorDefinition& _SensorDefinition);
} ;
void init_SensorDefinition(SensorDefinition& data);
		
// -------------------------------------------------------- RadarDefinition
// RadarDefinition is a structure
class RadarDefinition {
public:
	Long bandID;
	Real range;
	Real fov_deltaElevation;
	Real fov_deltaAzimut;
	Real for_elevationMin;
	Real for_elevationMax;
	Real for_azimutMin;
	Real for_azimutMax;
	Long toBeAcquiredDuration;
	Long toBeLostDuration;
	RadarDefinition() { }
	RadarDefinition(const RadarDefinition& _RadarDefinition);
	RadarDefinition& operator = (const RadarDefinition& _RadarDefinition);
	void copy(const RadarDefinition& _RadarDefinition);
} ;
void init_RadarDefinition(RadarDefinition& data);
		
// -------------------------------------------------------- EsmDefinition
// EsmDefinition is a structure
class EsmDefinition {
public:
	Long bandID;
	Real range;
	Real fov_deltaElevation;
	Real fov_deltaAzimut;
	Real for_elevationMin;
	Real for_elevationMax;
	Real for_azimutMin;
	Real for_azimutMax;
	Long toBeAcquiredDuration;
	Long toBeLostDuration;
	EsmDefinition() { }
	EsmDefinition(const EsmDefinition& _EsmDefinition);
	EsmDefinition& operator = (const EsmDefinition& _EsmDefinition);
	void copy(const EsmDefinition& _EsmDefinition);
} ;
void init_EsmDefinition(EsmDefinition& data);
		
// -------------------------------------------------------- SensorPlot
// SensorPlot is a structure
class SensorPlot {
public:
	Long date;
	Long sourceId;
	SensorType sourceType;
	Long sourceTechno;
	Real elevation;
	Real azimut;
	Real distance;
	Vec3 position;
	SensorPlot() { }
	SensorPlot(const SensorPlot& _SensorPlot);
	SensorPlot& operator = (const SensorPlot& _SensorPlot);
	void copy(const SensorPlot& _SensorPlot);
} ;
void init_SensorPlot(SensorPlot& data);
		
// -------------------------------------------------------- SensorImage
// SensorImage is a structure
class SensorImage {
public:
	SensorPlot plot;
	EntityStates objects;
	SensorImage() { }
	SensorImage(const SensorImage& _SensorImage);
	SensorImage& operator = (const SensorImage& _SensorImage);
	void copy(const SensorImage& _SensorImage);
} ;
void init_SensorImage(SensorImage& data);
		
// -------------------------------------------------------- SensorImages
// SensorImages is a vector of SensorImage
typedef std::vector<SensorImage> SensorImages ;
void init_SensorImages(SensorImages& data);
		
// -------------------------------------------------------- SensorPlotVector
// SensorPlotVector is a vector of SensorPlot
typedef std::vector<SensorPlot> SensorPlotVector ;
void init_SensorPlotVector(SensorPlotVector& data);
		
// -------------------------------------------------------- SensorTrack
// SensorTrack is a structure
class SensorTrack {
public:
	Long targetId;
	Long lastUpdateDate;
	SensorPlotVector plots;
	Long tracked;
	Long detected;
	Long trackTime;
	Real deltaAzimut;
	Real deltaElevation;
	Long doNotFollow;
	SensorTrack() { }
	SensorTrack(const SensorTrack& _SensorTrack);
	SensorTrack& operator = (const SensorTrack& _SensorTrack);
	void copy(const SensorTrack& _SensorTrack);
} ;
void init_SensorTrack(SensorTrack& data);
		
// -------------------------------------------------------- SensorTracks
// SensorTracks is a map with key type Long and value type SensorTrack
typedef std::map <Long, SensorTrack> SensorTracks;
void init_SensorTracks(SensorTracks& data);
		
// -------------------------------------------------------- SensorStatus
// SensorStatus is a structure
class SensorStatus {
public:
	Long lastUpdateDate;
	Long id;
	SensorType type;
	Long available;
	Long doingOrderId;
	Long doingOrderDuration;
	Long endOfOrderId;
	Long errorFlag;
	SensorStatus() { }
	SensorStatus(const SensorStatus& _SensorStatus);
	SensorStatus& operator = (const SensorStatus& _SensorStatus);
	void copy(const SensorStatus& _SensorStatus);
} ;
void init_SensorStatus(SensorStatus& data);
		
// -------------------------------------------------------- SensorsStatus
// SensorsStatus is a map with key type Long and value type SensorStatus
typedef std::map <Long, SensorStatus> SensorsStatus;
void init_SensorsStatus(SensorsStatus& data);
		
// -------------------------------------------------------- SensorOrder
// SensorOrder is a structure
class SensorOrder {
public:
	Long orderId;
	Long sensorId;
	SensorFunction func;
	Long fieldOfRegardNbr;
	Long fieldOfViewNbr;
	Real lineOfSightElevation;
	Real lineOfSightAzimut;
	Long duration;
	SensorOrder() { }
	SensorOrder(const SensorOrder& _SensorOrder);
	SensorOrder& operator = (const SensorOrder& _SensorOrder);
	void copy(const SensorOrder& _SensorOrder);
} ;
void init_SensorOrder(SensorOrder& data);
		
// -------------------------------------------------------- SensorOrders
// SensorOrders is a map with key type Long and value type SensorOrder
typedef std::map <Long, SensorOrder> SensorOrders;
void init_SensorOrders(SensorOrders& data);
		
// -------------------------------------------------------- SGD
// SGD is a structure
class SGD {
public:
	Long hasAB;
	Long hasBA;
	Long hasBA_RL;
	Long hasDist;
	Long hasIvisi;
	Real siteAB;
	Real giseAB;
	Real siteBA;
	Real giseBA;
	Real siteBA_RL;
	Real giseBA_RL;
	Real dist;
	Long ivisi;
	Long techno;
	Real range;
	SGD() { }
	SGD(const SGD& _SGD);
	SGD& operator = (const SGD& _SGD);
	void copy(const SGD& _SGD);
} ;
void init_SGD(SGD& data);
		
// -------------------------------------------------------- SensorMemory
// SensorMemory is a map with key type Long and value type SGD
typedef std::map <Long, SGD> SensorMemory;
void init_SensorMemory(SensorMemory& data);
		
// -------------------------------------------------------- SensorDefinitions
// SensorDefinitions is a map with key type Long and value type SensorDefinition
typedef std::map <Long, SensorDefinition> SensorDefinitions;
void init_SensorDefinitions(SensorDefinitions& data);
		
// -------------------------------------------------------- SAElementStatus
// SAElementStatus is a structure
class SAElementStatus {
public:
	Long nid;
	Long type;
	Long doing;
	Vec3 pos;
	Long date;
	Long status;
	Long targetId;
	Long munition;
	Long updated;
	SAElementStatus() { }
	SAElementStatus(const SAElementStatus& _SAElementStatus);
	SAElementStatus& operator = (const SAElementStatus& _SAElementStatus);
	void copy(const SAElementStatus& _SAElementStatus);
} ;
void init_SAElementStatus(SAElementStatus& data);
		
// -------------------------------------------------------- SAElementStatusList
// SAElementStatusList is a map with key type Long and value type SAElementStatus
typedef std::map <Long, SAElementStatus> SAElementStatusList;
void init_SAElementStatusList(SAElementStatusList& data);
		
// -------------------------------------------------------- SAElementOrder
// SAElementOrder is a structure
class SAElementOrder {
public:
	Long nid;
	Long orderId;
	Long order;
	Long targetId;
	SAElementOrder() { }
	SAElementOrder(const SAElementOrder& _SAElementOrder);
	SAElementOrder& operator = (const SAElementOrder& _SAElementOrder);
	void copy(const SAElementOrder& _SAElementOrder);
} ;
void init_SAElementOrder(SAElementOrder& data);
		
// -------------------------------------------------------- SAElementOrderList
// SAElementOrderList is a map with key type Long and value type SAElementOrder
typedef std::map <Long, SAElementOrder> SAElementOrderList;
void init_SAElementOrderList(SAElementOrderList& data);
		
// -------------------------------------------------------- SASystemState
// SASystemState is a structure
class SASystemState {
public:
	Long nid;
	Long state;
	Long ordersCount;
	Long nbrOfV;
	Long nbrOfCdT;
	Longs veilles;
	Longs cdts;
	Long nbrOfActiveV;
	Long nbrOfActiveCdT;
	SASystemState() { }
	SASystemState(const SASystemState& _SASystemState);
	SASystemState& operator = (const SASystemState& _SASystemState);
	void copy(const SASystemState& _SASystemState);
} ;
void init_SASystemState(SASystemState& data);
		
// -------------------------------------------------------- FlightData
// FlightData is a structure
class FlightData {
public:
	Vec3 position;
	Vec3 speed;
	Vec3 attitudes;
	Long date;
	FlightData() { }
	FlightData(const FlightData& _FlightData);
	FlightData& operator = (const FlightData& _FlightData);
	void copy(const FlightData& _FlightData);
} ;
void init_FlightData(FlightData& data);
		
// -------------------------------------------------------- NavigationData
// NavigationData is a structure
class NavigationData {
public:
	Vec3 position;
	Vec3 speed;
	Vec3 attitudes;
	Long date;
	Long wpId;
	Real distToNextWaypoint;
	NavigationPts nav;
	NavigationData() { }
	NavigationData(const NavigationData& _NavigationData);
	NavigationData& operator = (const NavigationData& _NavigationData);
	void copy(const NavigationData& _NavigationData);
} ;
void init_NavigationData(NavigationData& data);
		
// -------------------------------------------------------- NetworkDefinition
// NetworkDefinition is a structure
class NetworkDefinition {
public:
	String name;
	Long id;
	Long isBLOS;
	Real maxDist;
	Real networkBandwidth;
	Long maxSendConnectionPerAccess;
	Long maxRcvConnectionPerAccess;
	Real maxSendBandwidthPerConnection;
	Real maxRcvBandwidthPerAccess;
	Long maxConnectionInNetwork;
	Long maxNumberOfAccess;
	NetworkDefinition() { }
	NetworkDefinition(const NetworkDefinition& _NetworkDefinition);
	NetworkDefinition& operator = (const NetworkDefinition& _NetworkDefinition);
	void copy(const NetworkDefinition& _NetworkDefinition);
} ;
void init_NetworkDefinition(NetworkDefinition& data);
		
// -------------------------------------------------------- NetworkMessagePrivateHeader
// NetworkMessagePrivateHeader is a structure
class NetworkMessagePrivateHeader {
public:
	Long timestamp;
	Real sizeTransmitted;
	NetworkMessagePrivateHeader() { }
	NetworkMessagePrivateHeader(const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader);
	NetworkMessagePrivateHeader& operator = (const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader);
	void copy(const NetworkMessagePrivateHeader& _NetworkMessagePrivateHeader);
} ;
void init_NetworkMessagePrivateHeader(NetworkMessagePrivateHeader& data);
		
// -------------------------------------------------------- NetworkMessageUserHeader
// NetworkMessageUserHeader is a structure
class NetworkMessageUserHeader {
public:
	NetworkID networkId;
	Long fromId;
	Long toId;
	Long networkMsgId;
	Long dataSize;
	Long category;
	NetworkMessageUserHeader() { }
	NetworkMessageUserHeader(const NetworkMessageUserHeader& _NetworkMessageUserHeader);
	NetworkMessageUserHeader& operator = (const NetworkMessageUserHeader& _NetworkMessageUserHeader);
	void copy(const NetworkMessageUserHeader& _NetworkMessageUserHeader);
} ;
void init_NetworkMessageUserHeader(NetworkMessageUserHeader& data);
		
// -------------------------------------------------------- NetworkMessageUserData
// NetworkMessageUserData is a union
class NetworkMessageUserData {
protected:
	FlightData _FlightData_;	
	NavigationData _NavigationData_;	
	unsigned int type;
public:
	NetworkMessageUserData();
	static const unsigned int __FlightData;
	void set_FlightData(const FlightData& d);
	const FlightData* get_FlightData();
	const bool is_FlightData() { return (type == __FlightData); }
	static const unsigned int __NavigationData;
	void set_NavigationData(const NavigationData& d);
	const NavigationData* get_NavigationData();
	const bool is_NavigationData() { return (type == __NavigationData); }
	NetworkMessageUserData(const NetworkMessageUserData& _NetworkMessageUserData);
	~NetworkMessageUserData();
	NetworkMessageUserData& operator = (const NetworkMessageUserData& _NetworkMessageUserData);
	int getDataType() { return type; }
};
void init_NetworkMessageUserData(NetworkMessageUserData& data);
		
// -------------------------------------------------------- NetworkMessage
// NetworkMessage is a structure
class NetworkMessage {
public:
	NetworkMessageUserHeader uheader;
	NetworkMessagePrivateHeader pheader;
	NetworkMessageUserData data;
	NetworkMessage() { }
	NetworkMessage(const NetworkMessage& _NetworkMessage);
	NetworkMessage& operator = (const NetworkMessage& _NetworkMessage);
	void copy(const NetworkMessage& _NetworkMessage);
} ;
void init_NetworkMessage(NetworkMessage& data);
		
// -------------------------------------------------------- NetworkMessageDeliveryReport
// NetworkMessageDeliveryReport is a map with key type Long and value type Long
typedef std::map <Long, Long> NetworkMessageDeliveryReport;
void init_NetworkMessageDeliveryReport(NetworkMessageDeliveryReport& data);
		
// -------------------------------------------------------- NetworkMessageDeliveryReports
// NetworkMessageDeliveryReports is a map with key type Long and value type NetworkMessageDeliveryReport
typedef std::map <Long, NetworkMessageDeliveryReport> NetworkMessageDeliveryReports;
void init_NetworkMessageDeliveryReports(NetworkMessageDeliveryReports& data);
		
// -------------------------------------------------------- NetworkList
// NetworkList is a map with key type Long and value type Long
typedef std::map <Long, Long> NetworkList;
void init_NetworkList(NetworkList& data);
		
// -------------------------------------------------------- NetworkMessageList
// NetworkMessageList is a vector of NetworkMessage
typedef std::vector<NetworkMessage> NetworkMessageList ;
void init_NetworkMessageList(NetworkMessageList& data);
		
// -------------------------------------------------------- NetworkDefinitions
// NetworkDefinitions is a map with key type Long and value type NetworkDefinition
typedef std::map <Long, NetworkDefinition> NetworkDefinitions;
void init_NetworkDefinitions(NetworkDefinitions& data);
		
// -------------------------------------------------------- test
// test is a structure
class test {
public:
	Long fromId;
	Long toId;
	test() { }
	test(const test& _test);
	test& operator = (const test& _test);
	void copy(const test& _test);
} ;
void init_test(test& data);
		
// -------------------------------------------------------- TestMatlabStruct2
// TestMatlabStruct2 is a structure
class TestMatlabStruct2 {
public:
	Long i;
	Long j;
	Real x;
	TestMatlabStruct2() { }
	TestMatlabStruct2(const TestMatlabStruct2& _TestMatlabStruct2);
	TestMatlabStruct2& operator = (const TestMatlabStruct2& _TestMatlabStruct2);
	void copy(const TestMatlabStruct2& _TestMatlabStruct2);
} ;
void init_TestMatlabStruct2(TestMatlabStruct2& data);
		
// -------------------------------------------------------- TestMatlabStruct2List
// TestMatlabStruct2List is a vector of TestMatlabStruct2
typedef std::vector<TestMatlabStruct2> TestMatlabStruct2List ;
void init_TestMatlabStruct2List(TestMatlabStruct2List& data);
		
// -------------------------------------------------------- TestMatlabStruct
// TestMatlabStruct is a structure
class TestMatlabStruct {
public:
	Long unLong;
	Real unReal;
	Vec3 unVec3;
	Longs unVecteurDeLongs;
	TestMatlabStruct2List uneListe;
	TestMatlabStruct() { }
	TestMatlabStruct(const TestMatlabStruct& _TestMatlabStruct);
	TestMatlabStruct& operator = (const TestMatlabStruct& _TestMatlabStruct);
	void copy(const TestMatlabStruct& _TestMatlabStruct);
} ;
void init_TestMatlabStruct(TestMatlabStruct& data);
		
// -------------------------------------------------------- TestJavaStruct2
// TestJavaStruct2 is a structure
class TestJavaStruct2 {
public:
	Long i;
	Long j;
	Real x;
	TestJavaStruct2() { }
	TestJavaStruct2(const TestJavaStruct2& _TestJavaStruct2);
	TestJavaStruct2& operator = (const TestJavaStruct2& _TestJavaStruct2);
	void copy(const TestJavaStruct2& _TestJavaStruct2);
} ;
void init_TestJavaStruct2(TestJavaStruct2& data);
		
// -------------------------------------------------------- TestJavaStruct2List
// TestJavaStruct2List is a vector of TestJavaStruct2
typedef std::vector<TestJavaStruct2> TestJavaStruct2List ;
void init_TestJavaStruct2List(TestJavaStruct2List& data);
		
// -------------------------------------------------------- TestJavaStruct
// TestJavaStruct is a structure
class TestJavaStruct {
public:
	Long unLong;
	Real unReal;
	Vec3 unVec3;
	VecX unVecX;
	Longs unVecteurDeLongs;
	TestMatlabStruct2List uneListe;
	void allocate(unsigned int x, unsigned int y) {
		VecX_allocate(x, y);
	}
	TestJavaStruct() { }
	TestJavaStruct(const TestJavaStruct& _TestJavaStruct);
	TestJavaStruct& operator = (const TestJavaStruct& _TestJavaStruct);
	void copy(const TestJavaStruct& _TestJavaStruct);
} ;
void init_TestJavaStruct(TestJavaStruct& data);
		

// 
// ------------------------------------------------------------------------------------
//

} // eof namespace generated

#endif


