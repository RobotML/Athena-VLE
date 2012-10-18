
cmake_minimum_required(VERSION 2.8)

set(VLE_INCLUDE_DIRS /usr/include/vle-1.1/)
set(Boost_INCLUDE_DIRS /usr/include/boost)

include_directories(/usr/include/glib-2.0/)
include_directories(/usr/lib/i386-linux-gnu/glib-2.0/include)
include_directories(/usr/include/libxml2)

INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}
  ${VLE_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS})

LINK_DIRECTORIES(
  ${VLE_LIBRARY_DIRS}
  ${Boost_LIBRARY_DIRS})

ADD_LIBRARY(Model SHARED Model.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Model ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Function SHARED Function.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Function ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Equipment SHARED Equipment.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Equipment ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(SimulationObject SHARED SimulationObject.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SimulationObject ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Localisation SHARED Localisation.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Localisation ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Flight SHARED Flight.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Flight ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(BasicFlying SHARED BasicFlying.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(BasicFlying ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Navigation SHARED Navigation.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Navigation ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Communications SHARED Communications.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Communications ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Radar SHARED Radar.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Radar ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Esm SHARED Esm.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Esm ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Sensors SHARED Sensors.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Sensors ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Jammer SHARED Jammer.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Jammer ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Protection SHARED Protection.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Protection ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(WeapSys SHARED WeapSys.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(WeapSys ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(MMSMonitor SHARED MMSMonitor.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSMonitor ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(MMSExecute SHARED MMSExecute.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSExecute ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(MMSManage SHARED MMSManage.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSManage ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(MMSUpdate SHARED MMSUpdate.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMSUpdate ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(MMS SHARED MMS.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(MMS ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Aircraft SHARED Aircraft.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Aircraft ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(SAMComponent SHARED SAMComponent.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SAMComponent ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(SASystem SHARED SASystem.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(SASystem ${VLE_LIBRARIES} ${Boost_LIBRARIES} )

ADD_LIBRARY(Root SHARED Root.cpp TypeDefs.cc TypeDefs_Values.cc )
TARGET_LINK_LIBRARIES(Root ${VLE_LIBRARIES} ${Boost_LIBRARIES} )



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
  RUNTIME DESTINATION "plugins/simulator"
  LIBRARY DESTINATION "plugins/simulator"
  ARCHIVE DESTINATION "plugins/simulator")
