INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/src
  ${VLE_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS})

LINK_DIRECTORIES(
  ${VLE_LIBRARY_DIRS}
  ${Boost_LIBRARY_DIRS})

ADD_LIBRARY(XML STATIC xml.cpp tests.cpp expatpp.cpp xmlparse.c xmlrole.c xmltok.c xmltok_impl.c)
TARGET_LINK_LIBRARIES(XML ${VLE_LIBRARIES} ${BOOST_LIBRARIES})

ADD_LIBRARY(ExternalFunction SHARED FunctionDirectory.cpp FunctionLibrary.cpp)
TARGET_LINK_LIBRARIES(ExternalFunction XML ${VLE_LIBRARIES} ${BOOST_LIBRARIES})


ADD_LIBRARY(Model SHARED Model.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Model ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Function SHARED Function.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Function ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Equipment SHARED Equipment.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Equipment ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(SimulationObject SHARED SimulationObject.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SimulationObject ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Localisation SHARED Localisation.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Localisation ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Flight SHARED Flight.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Flight ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(BasicFlying SHARED BasicFlying.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(BasicFlying ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Navigation SHARED Navigation.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Navigation ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Communications SHARED Communications.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Communications ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Radar SHARED Radar.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Radar ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Esm SHARED Esm.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Esm ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Sensors SHARED Sensors.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Sensors ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Jammer SHARED Jammer.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Jammer ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Protection SHARED Protection.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Protection ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(WeapSys SHARED WeapSys.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(WeapSys ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(MMSMonitor SHARED MMSMonitor.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSMonitor ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(MMSExecute SHARED MMSExecute.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSExecute ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(MMSManage SHARED MMSManage.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSManage ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(MMSUpdate SHARED MMSUpdate.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSUpdate ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(MMS SHARED MMS.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMS ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Aircraft SHARED Aircraft.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Aircraft ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(SAMComponent SHARED SAMComponent.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SAMComponent ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(SASystem SHARED SASystem.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SASystem ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )
ADD_LIBRARY(Root SHARED Root.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Root ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Stub_BasicFlying SHARED Stub_BasicFlying.cpp TypeDefs.cc)
TARGET_LINK_LIBRARIES(Stub_BasicFlying ExternalFunction XML ${VLE_LIBRARIES} ${Boost_LIBRARIES})


INSTALL(TARGETS
  Model
  Function
  Equipment
  SimulationObject
  Localisation
  Flight
  BasicFlying
  Navigation
  Communications
  Radar
  Esm
  Sensors
  Jammer
  Protection
  WeapSys
  MMSMonitor
  MMSExecute
  MMSManage
  MMSUpdate
  MMS
  Aircraft
  SAMComponent
  SASystem
  Root
  Stub_BasicFlying
  ExternalFunction
  XML
  RUNTIME DESTINATION lib
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
