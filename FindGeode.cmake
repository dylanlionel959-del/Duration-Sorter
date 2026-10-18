# FindGeode.cmake - Localizador dinámico para el SDK de Geode
if(NOT TARGET Geode::Geode)
    if(NOT DEFINED ENV{GEODE_SDK})
        message(FATAL_ERROR "La variable de entorno GEODE_SDK no está definida.")
    endif()
    
    # Incluimos el archivo principal del SDK directamente desde la variable de entorno del action
    include("$ENV{GEODE_SDK}/Geode.cmake")
endif()
