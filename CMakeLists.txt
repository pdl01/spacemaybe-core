cmake_minimum_required (VERSION 2.6)
project (spacemaybe)
add_executable(spacemaybe 
src/abstractmission.h
src/attribute.cpp
src/attributefactory.cpp
src/attributefactory.h
src/attribute.h
src/coordinate.cpp
src/coordinate.h
src/game_engine.cpp
src/game_engine.h
src/game_objs.cpp
src/game_objs.h
src/growpopulationonplanetmission.cpp
src/growpopulationonplanetmission.h 
src/incrementagemission.h
src/incrementagemisson.cpp
src/mission.cpp
src/missionfactory.cpp
src/missionfactory.h
src/mission.h
src/planetarygeosection.cpp
src/planetarygeosection.h
src/planet.cpp
src/planetfactory.cpp
src/planetfactory.h
src/planet.h
src/populationgroup.cpp
src/planetfactory.h
src/planet.h
src/populationgroup.cpp
src/populationgroupfactory.cpp
src/populationgroupfactory.h
src/populationgroup.h
src/spacemaybe.cpp
src/technology.cpp
src/technologyfactory.cpp
src/technologyfactory.h
src/technology.h
src/vgame.cpp
src/vgame.h
        )   

find_package(SFML COMPONENTS system window graphics)

target_link_libraries(spacemaybe PRIVATE sfml-system sfml-graphics sfml-window ) 
#target_link_libraries(main PRIVATE sfml-graphics)
#sfml is installed here /usr/lib/x86_64-linux-gnu