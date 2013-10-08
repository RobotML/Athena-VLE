#ifndef Stub_BasicFlying_H
#define Stub_BasicFlying_H
//----------------------------------------------------------------
//	INCLUDES FILES
//----------------------------------------------------------------
#include <vle/utils/DateTime.hpp>
#include <vle/utils/Trace.hpp>
#include <boost/function.hpp>
#include "Compatibility.hpp"
#include "FunctionDirectory.hpp"
#include "TypeDefs.h"

using namespace generated;
namespace vu = vle::utils;
//----------------------------------------------------------------
//	USER FUNCTIONS DECLARATION
//----------------------------------------------------------------
__EXPORT__ void initBasicFlying(const Long& nid, const Long& time, const Long& timestep);
__EXPORT__ void stepBasicFlying(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls);
__EXPORT__ void initNetworks(NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr);
__EXPORT__ void stepNetworks(const Long& time, const Long& timestep, const Pointer& networksPtr, const EnvironmentInteractions& interactions);
__EXPORT__ void basicCommunicationManagementSND(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, const NetworkMessageList& send, NetworkMessageDeliveryReports& reports);
__EXPORT__ void basicCommunicationManagementRCV(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageList& rcvd, NetworkMessageDeliveryReports& reports);
__EXPORT__ void basicMessageRouting(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd);
__EXPORT__ void initLocalisation(const Long& nid, const Long& loc_const_id, LocDefinitions& loc_def, LocalisationConst& lconst, LocalisationEquipmentState& leqps, LocalisationError& lerror);
__EXPORT__ void stepLocalisation(const Long& time, const Long& timestep, const Long& nid, const LocalisationConst& lconst, LocalisationEquipmentState& leqps, const LocalisationState& lstate, LocalisationError& lerror);
__EXPORT__ void initFlightAndNavModels(const Long& nid, const Long& timestep, const LocalisationInit& linit, NavigationState& ns, SStateVector& ssv, LocalisationState& ls);
__EXPORT__ void stepFlightAndNavModels(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls);
__EXPORT__ void stepFlightModel(const Long& time, const Long& timestep, const Long& nid, NavigationState& ns, SStateVector& ssv, LocalisationState& ls);
__EXPORT__ void stepNavModel(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns);
__EXPORT__ void mmsMonitorNavigation(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsMonitorComms(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsMonitorSensors(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsMonitorAutoprot(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsMonitorWeapons(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsExecuteNavigation(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsExecuteComms(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsExecuteSensors(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsExecuteAutoprot(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void mmsExecuteWeapons(const Long& time, const Long& timestep, const Long& nid);
__EXPORT__ void publishStateVectorOnNetwork(const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count);
__EXPORT__ void readStateVectorOnNetwork(const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received);
__EXPORT__ void pushStatus(const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list);
__EXPORT__ void sensorInit(const Long& nid, const Long& sensorId, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile);
__EXPORT__ void sensorStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorImages& images, SensorTracks& tracks);
__EXPORT__ void radarInit(const Long& nid, const Long& sensorId, const RadarDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile);
__EXPORT__ void radarStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks);
__EXPORT__ void esmInit(const Long& nid, const Long& sensorId, const EsmDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile);
__EXPORT__ void esmStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks);
__EXPORT__ void aircraftSensorsManagement(const Long& time, const Long& timestep, const Long& nid, const SensorsStatus& statusList, Long& orderCount, SensorOrders& orders, const SensorImages& images, const SensorTracks& tracks);
__EXPORT__ void jammerInit(const Long& nid, const Long& jammerId, const Long& jammerDefId, JammerDefinitions& defs, JammerDefinition& def, JammerStatus& s, JammersStatus& stl);
__EXPORT__ void jammerStep(const Long& time, const Long& timestep, const Long& nid, const JammerDefinition& def, JammerStatus& status, JammersStatus& statusList, const JammersOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI);
__EXPORT__ void jammersManagement(const Long& time, const Long& timestep, const Long& nid, const JammersStatus& statusList, Long& orderCount, JammersOrders& orders);
__EXPORT__ void advanceTime(const Long& timestep, Long& time, Long& cycle);
__EXPORT__ void updateAircraftEntityState(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const SStateVector& ssv, EnvironmentInteractions& EI);
__EXPORT__ void updateStaticEntityState(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const Vec3& pos, EnvironmentInteractions& EI);
__EXPORT__ void showInteractions(const Long& time, const EnvironmentInteractions& eis);
__EXPORT__ void cleanInteractions(const Long& time, const Long& timestep, EnvironmentInteractions& eis);
__EXPORT__ void showEntity(const Long& time, const EntityState& es);
__EXPORT__ void applyExternalInputs(const Long& time, const Long& timestep, ExternalInputList& extInputList, EquipmentStatusList& commsSL);
__EXPORT__ void initSAMComponent(const Long& nid, const Real& hA, Vec3& pos);
__EXPORT__ void manageSASystem(const Long& time, const Long& timestep, const Long& nid, SASystemState& systemState, const SAElementStatusList& statusList, SAElementOrderList& orderList, const SensorTracks& tracks);
__EXPORT__ void manageSA(const Long& time, const Long& timestep, const Long& nid, const Long& subType, const Vec3& pos, SAElementStatusList& statusList, const SAElementOrderList& sysOrdersList, SensorOrders& sensorOrdersList, SensorTracks& tracks);

//----------------------------------------------------------------
//	USER PROCESSING DECLARATION
//----------------------------------------------------------------
extern "C" __EXPORT__ void commsManagement(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageDeliveryReports& reports, const Long& nav_msgCategoryId, const NetworkMessageList& nav_toBeSent, NetworkMessageList& nav_rcvd, const Long& mms_msgCategoryId, const NetworkMessageList& mms_toBeSent, NetworkMessageList& mms_rcvd);
extern "C" __EXPORT__ void updatePosition(const Long& time, const Long& timestep, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const NavigationUpdate& nav_update, NavigationState& nav_state, SStateVector& ssv, LocalisationState& ls, EnvironmentInteractions& EI);
extern "C" __EXPORT__ void pEsmStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, SensorsStatus& statusList, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks);
extern "C" __EXPORT__ void pRootInit(Long& time, const Long& timestep, Long& cycle, const Long& interactionCleanningTimeStep, NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr, EnvironmentInteractions& interactions);
extern "C" __EXPORT__ void pRootStep(Long& time, const Long& timestep, Long& cycle, const Pointer& networksPtr, const Long& interactionCleanningTimeStep, EnvironmentInteractions& interactions);
extern "C" __EXPORT__ void pRadarStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, SensorsStatus& statusList, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks);
extern "C" __EXPORT__ void pSAMComponentInit(const Long& NID, const Real& ha, Vec3& position, const Long& sensorId, const RadarDefinition& radarDef, SensorDefinition& sensorDef, SensorStatus& sstatus, const String& distSensorDomainFilePath, const String& distJammerDomainFilePath);
extern "C" __EXPORT__ void pSAMComponentStep(const Long& time, const Long& timestep, const Long& NID, const SensorDefinition& sensorDef, SensorStatus& sstatus, SensorOrders& sorders, EnvironmentInteractions& interactions, SensorTracks& tracks, const Long& sideId, const EntityType& TYPE, const Long& SUBTYPE, const Vec3& position, SAElementStatusList& statusList, const SAElementOrderList& ordersList);
extern "C" __EXPORT__ void pMMSExecute(const Long& time, const Long& timestep, const Long& NID);
extern "C" __EXPORT__ void pMMSMonitor(const Long& time, const Long& timestep, const Long& NID);
extern "C" __EXPORT__ void pNavigationStep(const Long& time, const Long& timestep, const Long& NID, const NavigationState& nav_state, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& nav_toBeSent, Long& count, const NetworkMessageList& nav_received);

//----------------------------------------------------------------
// User Function To Directory
//----------------------------------------------------------------


namespace generated {

class Stub_BasicFlying {
public:
	Stub_BasicFlying() {
		_pFuncDirectory->addFunction("initBasicFlying", (void*)&initBasicFlying);
		_pFuncDirectory->addFunction("stepBasicFlying", (void*)&stepBasicFlying);
		_pFuncDirectory->addFunction("initNetworks", (void*)&initNetworks);
		_pFuncDirectory->addFunction("stepNetworks", (void*)&stepNetworks);
		_pFuncDirectory->addFunction("basicCommunicationManagementSND", (void*)&basicCommunicationManagementSND);
		_pFuncDirectory->addFunction("basicCommunicationManagementRCV", (void*)&basicCommunicationManagementRCV);
		_pFuncDirectory->addFunction("basicMessageRouting", (void*)&basicMessageRouting);
		_pFuncDirectory->addFunction("initLocalisation", (void*)&initLocalisation);
		_pFuncDirectory->addFunction("stepLocalisation", (void*)&stepLocalisation);
		_pFuncDirectory->addFunction("initFlightAndNavModels", (void*)&initFlightAndNavModels);
		_pFuncDirectory->addFunction("stepFlightAndNavModels", (void*)&stepFlightAndNavModels);
		_pFuncDirectory->addFunction("stepFlightModel", (void*)&stepFlightModel);
		_pFuncDirectory->addFunction("stepNavModel", (void*)&stepNavModel);
		_pFuncDirectory->addFunction("mmsMonitorNavigation", (void*)&mmsMonitorNavigation);
		_pFuncDirectory->addFunction("mmsMonitorComms", (void*)&mmsMonitorComms);
		_pFuncDirectory->addFunction("mmsMonitorSensors", (void*)&mmsMonitorSensors);
		_pFuncDirectory->addFunction("mmsMonitorAutoprot", (void*)&mmsMonitorAutoprot);
		_pFuncDirectory->addFunction("mmsMonitorWeapons", (void*)&mmsMonitorWeapons);
		_pFuncDirectory->addFunction("mmsExecuteNavigation", (void*)&mmsExecuteNavigation);
		_pFuncDirectory->addFunction("mmsExecuteComms", (void*)&mmsExecuteComms);
		_pFuncDirectory->addFunction("mmsExecuteSensors", (void*)&mmsExecuteSensors);
		_pFuncDirectory->addFunction("mmsExecuteAutoprot", (void*)&mmsExecuteAutoprot);
		_pFuncDirectory->addFunction("mmsExecuteWeapons", (void*)&mmsExecuteWeapons);
		_pFuncDirectory->addFunction("publishStateVectorOnNetwork", (void*)&publishStateVectorOnNetwork);
		_pFuncDirectory->addFunction("readStateVectorOnNetwork", (void*)&readStateVectorOnNetwork);
		_pFuncDirectory->addFunction("pushStatus", (void*)&pushStatus);
		_pFuncDirectory->addFunction("sensorInit", (void*)&sensorInit);
		_pFuncDirectory->addFunction("sensorStep", (void*)&sensorStep);
		_pFuncDirectory->addFunction("radarInit", (void*)&radarInit);
		_pFuncDirectory->addFunction("radarStep", (void*)&radarStep);
		_pFuncDirectory->addFunction("esmInit", (void*)&esmInit);
		_pFuncDirectory->addFunction("esmStep", (void*)&esmStep);
		_pFuncDirectory->addFunction("aircraftSensorsManagement", (void*)&aircraftSensorsManagement);
		_pFuncDirectory->addFunction("jammerInit", (void*)&jammerInit);
		_pFuncDirectory->addFunction("jammerStep", (void*)&jammerStep);
		_pFuncDirectory->addFunction("jammersManagement", (void*)&jammersManagement);
		_pFuncDirectory->addFunction("advanceTime", (void*)&advanceTime);
		_pFuncDirectory->addFunction("updateAircraftEntityState", (void*)&updateAircraftEntityState);
		_pFuncDirectory->addFunction("updateStaticEntityState", (void*)&updateStaticEntityState);
		_pFuncDirectory->addFunction("showInteractions", (void*)&showInteractions);
		_pFuncDirectory->addFunction("cleanInteractions", (void*)&cleanInteractions);
		_pFuncDirectory->addFunction("showEntity", (void*)&showEntity);
		_pFuncDirectory->addFunction("applyExternalInputs", (void*)&applyExternalInputs);
		_pFuncDirectory->addFunction("initSAMComponent", (void*)&initSAMComponent);
		_pFuncDirectory->addFunction("manageSASystem", (void*)&manageSASystem);
		_pFuncDirectory->addFunction("manageSA", (void*)&manageSA);
		_pFuncDirectory->addFunction("commsManagement", (void*)&commsManagement);
		_pFuncDirectory->addFunction("updatePosition", (void*)&updatePosition);
		_pFuncDirectory->addFunction("pEsmStep", (void*)&pEsmStep);
		_pFuncDirectory->addFunction("pRootInit", (void*)&pRootInit);
		_pFuncDirectory->addFunction("pRootStep", (void*)&pRootStep);
		_pFuncDirectory->addFunction("pRadarStep", (void*)&pRadarStep);
		_pFuncDirectory->addFunction("pSAMComponentInit", (void*)&pSAMComponentInit);
		_pFuncDirectory->addFunction("pSAMComponentStep", (void*)&pSAMComponentStep);
		_pFuncDirectory->addFunction("pMMSExecute", (void*)&pMMSExecute);
		_pFuncDirectory->addFunction("pMMSMonitor", (void*)&pMMSMonitor);
		_pFuncDirectory->addFunction("pNavigationStep", (void*)&pNavigationStep);
	}
};
Stub_BasicFlying Stub_BasicFlying_Obj;
}
//----------------------------------------------------------------
// User Function Wrapper Implementations
//----------------------------------------------------------------
/**
 * stub function
 */
__EXPORT__ void sensorInit(const Long& nid, const Long& sensorId, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pNavigationStep BEGIN");
	
	Long nav_msgCategoryId, time, timestep, count;
	NetworkMessageList nav_received, nav_toBeSent;
	SStateVector ssv;
	NavigationState nav_state;
	
	//publishStateVectorOnNetwork
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count)> _publishStateVectorOnNetwork = (void (*)(const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count)) _pFuncDirectory->getFunction("publishStateVectorOnNetwork");
		_publishStateVectorOnNetwork(time, timestep, nid, nav_state, ssv, nav_msgCategoryId, nav_toBeSent, count);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function publishStateVectorOnNetwork !!!!!");
	}
	
	//readStateVectorOnNetwork
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received)> _readStateVectorOnNetwork = (void (*)(const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received)) _pFuncDirectory->getFunction("readStateVectorOnNetwork");
		_readStateVectorOnNetwork(time, timestep, nid, nav_msgCategoryId, nav_received);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function readStateVectorOnNetwork !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pNavigationStep END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void sensorStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorImages& images, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::sensorStep BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::sensorStep END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void showEntity(const Long& time, const EntityState& es)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::showEntity BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::showEntity END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void advanceTime(const Long& timestep, Long& time, Long& cycle)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::advanceTime BEGIN"); 
	time += timestep;
	cycle ++;
	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::advanceTime END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void initNetworks(NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initNetworks BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initNetworks END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepNavModel(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepNavModel BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepNavModel END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepNetworks(const Long& time, const Long& timestep, const Pointer& networksPtr, const EnvironmentInteractions& interactions)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepNetworks BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepNetworks END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepBasicFlying(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepBasicFlying BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepBasicFlying END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepFlightModel(const Long& time, const Long& timestep, const Long& nid, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepFlightModel BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepFlightModel END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void showInteractions(const Long& time, const EnvironmentInteractions& eis)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::showInteractions BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::showInteractions END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void cleanInteractions(const Long& time, const Long& timestep, EnvironmentInteractions& eis)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::cleanInteractions BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::cleanInteractions END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsExecuteAutoprot(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteAutoprot BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteAutoprot END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsMonitorAutoprot(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorAutoprot BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorAutoprot END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void manageSASystem(const Long& time, const Long& timestep, const Long& nid, SASystemState& systemState, const SAElementStatusList& statusList, SAElementOrderList& orderList, const SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::manageSASystem BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::manageSASystem END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void manageSA(const Long& time, const Long& timestep, const Long& nid, const Long& subType, const Vec3& pos, SAElementStatusList& statusList, const SAElementOrderList& sysOrdersList, SensorOrders& sensorOrdersList, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::manageSA BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::manageSA END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void initSAMComponent(const Long& nid, const Real& hA, Vec3& pos)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initSAMComponent BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initSAMComponent END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void radarStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::radarStep BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::radarStep END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void updateStaticEntityState(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const Vec3& pos, EnvironmentInteractions& EI)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updateStaticEntityState BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updateStaticEntityState END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void radarInit(const Long& nid, const Long& sensorId, const RadarDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::radarInit BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::radarInit END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void applyExternalInputs(const Long& time, const Long& timestep, ExternalInputList& extInputList, EquipmentStatusList& commsSL)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::applyExternalInputs BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::applyExternalInputs END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsExecuteWeapons(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteWeapons BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteWeapons END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsExecuteNavigation(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteNavigation BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteNavigation END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsExecuteSensors(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteSensors BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteSensors END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsExecuteComms(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteComms BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsExecuteComms END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsMonitorSensors(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorSensors BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorSensors END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsMonitorWeapons(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorWeapons BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorWeapons END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsMonitorNavigation(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorNavigation BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorNavigation END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void mmsMonitorComms(const Long& time, const Long& timestep, const Long& nid)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorComms BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::mmsMonitorComms END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void jammersManagement(const Long& time, const Long& timestep, const Long& nid, const JammersStatus& statusList, Long& orderCount, JammersOrders& orders)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammersManagement BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammersManagement END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void jammerStep(const Long& time, const Long& timestep, const Long& nid, const JammerDefinition& def, JammerStatus& status, JammersStatus& statusList, const JammersOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammerStep BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammerStep END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void jammerInit(const Long& nid, const Long& jammerId, const Long& jammerDefId, JammerDefinitions& defs, JammerDefinition& def, JammerStatus& s, JammersStatus& stl)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammerInit BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::jammerInit END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void aircraftSensorsManagement(const Long& time, const Long& timestep, const Long& nid, const SensorsStatus& statusList, Long& orderCount, SensorOrders& orders, const SensorImages& images, const SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::aircraftSensorsManagement BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::aircraftSensorsManagement END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void pushStatus(const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pushStatus BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pushStatus END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void esmStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::esmStep BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::esmStep END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void esmInit(const Long& nid, const Long& sensorId, const EsmDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::esmInit BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::esmInit END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void basicMessageRouting(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicMessageRouting BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicMessageRouting END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void basicCommunicationManagementRCV(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageList& rcvd, NetworkMessageDeliveryReports& reports)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicCommunicationManagementRCV BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicCommunicationManagementRCV END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void basicCommunicationManagementSND(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, const NetworkMessageList& send, NetworkMessageDeliveryReports& reports)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicCommunicationManagementSND BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::basicCommunicationManagementSND END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void publishStateVectorOnNetwork(const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::publishStateVectorOnNetwork BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::publishStateVectorOnNetwork END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void readStateVectorOnNetwork(const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::readStateVectorOnNetwork BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::readStateVectorOnNetwork END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void initBasicFlying(const Long& nid, const Long& time, const Long& timestep)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initBasicFlying BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initBasicFlying END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepFlightAndNavModels(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepFlightAndNavModels BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepFlightAndNavModels END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void initFlightAndNavModels(const Long& nid, const Long& timestep, const LocalisationInit& linit, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initFlightAndNavModels BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initFlightAndNavModels END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void updateAircraftEntityState(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const SStateVector& ssv, EnvironmentInteractions& EI)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updateAircraftEntityState BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updateAircraftEntityState END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void initLocalisation(const Long& nid, const Long& loc_const_id, LocDefinitions& loc_def, LocalisationConst& lconst, LocalisationEquipmentState& leqps, LocalisationError& lerror)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initLocalisation BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::initLocalisation END");
	// End of user code
}
/**
 * stub function
 */
__EXPORT__ void stepLocalisation(const Long& time, const Long& timestep, const Long& nid, const LocalisationConst& lconst, LocalisationEquipmentState& leqps, const LocalisationState& lstate, LocalisationError& lerror)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepLocalisation BEGIN"); 

	

	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::stepLocalisation END");
	// End of user code
}

//----------------------------------------------------------------
// User Function Wrapper Implementations
//----------------------------------------------------------------
/**
* stub processing
*/
__EXPORT__ void pRadarStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, SensorsStatus& statusList, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRadarStep BEGIN");
	
	
	//radarStep
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)> _radarStep = (void (*)(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)) _pFuncDirectory->getFunction("radarStep");
		_radarStep(time, timestep, nid, def, status, orders, currentEI, newEI, tracks);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function radarStep !!!!!");
	}
	
	//pushStatus
	try
	{
	boost::function<void (const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list)> _pushStatus = (void (*)(const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list)) _pFuncDirectory->getFunction("pushStatus");
		_pushStatus(def, status, statusList);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function pushStatus !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRadarStep END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pEsmStep(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, SensorsStatus& statusList, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pEsmStep BEGIN");
	
	
	//esmStep
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)> _esmStep = (void (*)(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)) _pFuncDirectory->getFunction("esmStep");
		_esmStep(time, timestep, nid, def, status, orders, currentEI, newEI, tracks);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function esmStep !!!!!");
	}
	
	//pushStatus
	try
	{
	boost::function<void (const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list)> _pushStatus = (void (*)(const SensorDefinition& def, const SensorStatus& s, SensorsStatus& list)) _pFuncDirectory->getFunction("pushStatus");
		_pushStatus(def, status, statusList);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function pushStatus !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pEsmStep END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void commsManagement(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageDeliveryReports& reports, const Long& nav_msgCategoryId, const NetworkMessageList& nav_toBeSent, NetworkMessageList& nav_rcvd, const Long& mms_msgCategoryId, const NetworkMessageList& mms_toBeSent, NetworkMessageList& mms_rcvd)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::commsManagement BEGIN");
	NetworkMessageList toBeSent;
	NetworkMessageList rcvd;
	
	
	//basicCommunicationManagementRCV
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageList& rcvd, NetworkMessageDeliveryReports& reports)> _basicCommunicationManagementRCV = (void (*)(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageList& rcvd, NetworkMessageDeliveryReports& reports)) _pFuncDirectory->getFunction("basicCommunicationManagementRCV");
		_basicCommunicationManagementRCV(time, timestep, nid, statusList, networksPtr, initialized, rcvd, reports);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function basicCommunicationManagementRCV !!!!!");
	}
	
	//basicMessageRouting
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd)> _basicMessageRouting = (void (*)(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd)) _pFuncDirectory->getFunction("basicMessageRouting");
		_basicMessageRouting(time, timestep, nid, statusList, nav_msgCategoryId, toBeSent, rcvd, nav_toBeSent, nav_rcvd);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function basicMessageRouting !!!!!");
	}
	
	//basicMessageRouting
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd)> _basicMessageRouting = (void (*)(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Long& msgCategoryId, NetworkMessageList& toBeSent, const NetworkMessageList& rcvd, const NetworkMessageList& func_toBeSent, NetworkMessageList& func_rcvd)) _pFuncDirectory->getFunction("basicMessageRouting");
		_basicMessageRouting(time, timestep, nid, statusList, mms_msgCategoryId, toBeSent, rcvd, mms_toBeSent, mms_rcvd);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function basicMessageRouting !!!!!");
	}
	
	//basicCommunicationManagementSND
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, const NetworkMessageList& send, NetworkMessageDeliveryReports& reports)> _basicCommunicationManagementSND = (void (*)(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, const NetworkMessageList& send, NetworkMessageDeliveryReports& reports)) _pFuncDirectory->getFunction("basicCommunicationManagementSND");
		_basicCommunicationManagementSND(time, timestep, nid, statusList, networksPtr, initialized, toBeSent, reports);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function basicCommunicationManagementSND !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::commsManagement END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void updatePosition(const Long& time, const Long& timestep, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const NavigationUpdate& nav_update, NavigationState& nav_state, SStateVector& ssv, LocalisationState& ls, EnvironmentInteractions& EI)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updatePosition BEGIN");
	
	
	//stepFlightAndNavModels
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)> _stepFlightAndNavModels = (void (*)(const Long& time, const Long& timestep, const Long& nid, const NavigationUpdate& nav_update, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)) _pFuncDirectory->getFunction("stepFlightAndNavModels");
		_stepFlightAndNavModels(time, timestep, nid, nav_update, nav_state, ssv, ls);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function stepFlightAndNavModels !!!!!");
	}
	
	//updateAircraftEntityState
	try
	{
	boost::function<void (const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const SStateVector& ssv, EnvironmentInteractions& EI)> _updateAircraftEntityState = (void (*)(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const SStateVector& ssv, EnvironmentInteractions& EI)) _pFuncDirectory->getFunction("updateAircraftEntityState");
		_updateAircraftEntityState(time, nid, sideId, type, subType, ssv, EI);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function updateAircraftEntityState !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::updatePosition END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pSAMComponentStep(const Long& time, const Long& timestep, const Long& NID, const SensorDefinition& sensorDef, SensorStatus& sstatus, SensorOrders& sorders, EnvironmentInteractions& interactions, SensorTracks& tracks, const Long& sideId, const EntityType& TYPE, const Long& SUBTYPE, const Vec3& position, SAElementStatusList& statusList, const SAElementOrderList& ordersList)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pSAMComponentStep BEGIN");
	
	
	//radarStep
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)> _radarStep = (void (*)(const Long& time, const Long& timestep, const Long& nid, const SensorDefinition& def, SensorStatus& status, const SensorOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI, SensorTracks& tracks)) _pFuncDirectory->getFunction("radarStep");
		_radarStep(time, timestep, NID, sensorDef, sstatus, sorders, interactions, interactions, tracks);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function radarStep !!!!!");
	}
	
	//updateStaticEntityState
	try
	{
	boost::function<void (const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const Vec3& pos, EnvironmentInteractions& EI)> _updateStaticEntityState = (void (*)(const Long& time, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const Vec3& pos, EnvironmentInteractions& EI)) _pFuncDirectory->getFunction("updateStaticEntityState");
		_updateStaticEntityState(time, NID, sideId, TYPE, SUBTYPE, position, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function updateStaticEntityState !!!!!");
	}
	
	//manageSA
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const Long& subType, const Vec3& pos, SAElementStatusList& statusList, const SAElementOrderList& sysOrdersList, SensorOrders& sensorOrdersList, SensorTracks& tracks)> _manageSA = (void (*)(const Long& time, const Long& timestep, const Long& nid, const Long& subType, const Vec3& pos, SAElementStatusList& statusList, const SAElementOrderList& sysOrdersList, SensorOrders& sensorOrdersList, SensorTracks& tracks)) _pFuncDirectory->getFunction("manageSA");
		_manageSA(time, timestep, NID, SUBTYPE, position, statusList, ordersList, sorders, tracks);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function manageSA !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pSAMComponentStep END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pRootStep(Long& time, const Long& timestep, Long& cycle, const Pointer& networksPtr, const Long& interactionCleanningTimeStep, EnvironmentInteractions& interactions)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRootStep BEGIN");
	
	
	//stepNetworks
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Pointer& networksPtr, const EnvironmentInteractions& interactions)> _stepNetworks = (void (*)(const Long& time, const Long& timestep, const Pointer& networksPtr, const EnvironmentInteractions& interactions)) _pFuncDirectory->getFunction("stepNetworks");
		_stepNetworks(time, timestep, networksPtr, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function stepNetworks !!!!!");
	}
	
	//showInteractions
	try
	{
	boost::function<void (const Long& time, const EnvironmentInteractions& eis)> _showInteractions = (void (*)(const Long& time, const EnvironmentInteractions& eis)) _pFuncDirectory->getFunction("showInteractions");
		_showInteractions(time, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function showInteractions !!!!!");
	}
	
	//cleanInteractions
	try
	{
	boost::function<void (const Long& time, const Long& timestep, EnvironmentInteractions& eis)> _cleanInteractions = (void (*)(const Long& time, const Long& timestep, EnvironmentInteractions& eis)) _pFuncDirectory->getFunction("cleanInteractions");
		_cleanInteractions(time, interactionCleanningTimeStep, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function cleanInteractions !!!!!");
	}
	
	//advanceTime
	try
	{
	boost::function<void (const Long& timestep, Long& time, Long& cycle)> _advanceTime = (void (*)(const Long& timestep, Long& time, Long& cycle)) _pFuncDirectory->getFunction("advanceTime");
		_advanceTime(timestep, time, cycle);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function advanceTime !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRootStep END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pRootInit(Long& time, const Long& timestep, Long& cycle, const Long& interactionCleanningTimeStep, NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr, EnvironmentInteractions& interactions)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRootInit BEGIN");
	time = 0;
	cycle = 0;
	
	//initNetworks
	try
	{
	boost::function<void (NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr)> _initNetworks = (void (*)(NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr)) _pFuncDirectory->getFunction("initNetworks");
		_initNetworks(networkDefs, networkList, networksPtr);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function initNetworks !!!!!");
	}
	
	//showInteractions
	try
	{
	boost::function<void (const Long& time, const EnvironmentInteractions& eis)> _showInteractions = (void (*)(const Long& time, const EnvironmentInteractions& eis)) _pFuncDirectory->getFunction("showInteractions");
		_showInteractions(time, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function showInteractions !!!!!");
	}
	
	//cleanInteractions
	try
	{
	boost::function<void (const Long& time, const Long& timestep, EnvironmentInteractions& eis)> _cleanInteractions = (void (*)(const Long& time, const Long& timestep, EnvironmentInteractions& eis)) _pFuncDirectory->getFunction("cleanInteractions");
		_cleanInteractions(time, interactionCleanningTimeStep, interactions);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function cleanInteractions !!!!!");
	}
	
	//advanceTime
	try
	{
	boost::function<void (const Long& timestep, Long& time, Long& cycle)> _advanceTime = (void (*)(const Long& timestep, Long& time, Long& cycle)) _pFuncDirectory->getFunction("advanceTime");
		_advanceTime(timestep, time, cycle);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function advanceTime !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pRootInit END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pSAMComponentInit(const Long& NID, const Real& ha, Vec3& position, const Long& sensorId, const RadarDefinition& radarDef, SensorDefinition& sensorDef, SensorStatus& sstatus, const String& distSensorDomainFilePath, const String& distJammerDomainFilePath)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pSAMComponentInit BEGIN");
	
	
	//radarInit
	try
	{
	boost::function<void (const Long& nid, const Long& sensorId, const RadarDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile)> _radarInit = (void (*)(const Long& nid, const Long& sensorId, const RadarDefinition& rdef, SensorDefinition& def, SensorStatus& s, const String& distSensorDomainFile, const String& distJammerDomainFile)) _pFuncDirectory->getFunction("radarInit");
		_radarInit(NID, sensorId, radarDef, sensorDef, sstatus, distSensorDomainFilePath, distJammerDomainFilePath);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function radarInit !!!!!");
	}
	
	//initSAMComponent
	try
	{
	boost::function<void (const Long& nid, const Real& hA, Vec3& pos)> _initSAMComponent = (void (*)(const Long& nid, const Real& hA, Vec3& pos)) _pFuncDirectory->getFunction("initSAMComponent");
		_initSAMComponent(NID, ha, position);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function initSAMComponent !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pSAMComponentInit END");
	// End of user code
}
/**
* stub processing
*/
__EXPORT__ void pNavigationStep(const Long& time, const Long& timestep, const Long& NID, const NavigationState& nav_state, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& nav_toBeSent, Long& count, const NetworkMessageList& nav_received)
{
	// Start of user code wrapper
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pNavigationStep BEGIN");
	
	
	//publishStateVectorOnNetwork
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count)> _publishStateVectorOnNetwork = (void (*)(const Long& time, const Long& timestep, const Long& nid, const NavigationState& ns, const SStateVector& ssv, const Long& nav_msgCategoryId, NetworkMessageList& toBeSent, Long& count)) _pFuncDirectory->getFunction("publishStateVectorOnNetwork");
		_publishStateVectorOnNetwork(time, timestep, NID, nav_state, ssv, nav_msgCategoryId, nav_toBeSent, count);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function publishStateVectorOnNetwork !!!!!");
	}
	
	//readStateVectorOnNetwork
	try
	{
	boost::function<void (const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received)> _readStateVectorOnNetwork = (void (*)(const Long& time, const Long& timestep, const Long& nid, const Long& nav_msgCategoryId, const NetworkMessageList& received)) _pFuncDirectory->getFunction("readStateVectorOnNetwork");
		_readStateVectorOnNetwork(time, timestep, NID, nav_msgCategoryId, nav_received);
	}
	catch(...)
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " !!!!! Problem on loading function readStateVectorOnNetwork !!!!!");
	}
	
	TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pNavigationStep END");
	// End of user code
}

__EXPORT__ void pMMSExecute(const Long& time, const Long& timestep, const Long& NID)
{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pMMSExecute BEGIN");
		TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pMMSExecute END");
}
__EXPORT__ void pMMSMonitor(const Long& time, const Long& timestep, const Long& NID)
{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pMMSMonitor BEGIN");
		TraceAlways(vu::DateTime::simpleCurrentDate() + " BasicFlying::pMMSMonitor END");
}


#endif /* Stub_BasicFlying_H */
