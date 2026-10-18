# FindGeode.cmake - Localizador robusto para Geode SDK en CI
if(NOT TARGET Geode::Geode)
    # Buscamos primero en la variable de entorno, luego en la ruta estándar del workspace de GitHub Actions
    if(EXISTS "$ENV{GEODE_SDK}/Geode.cmake")
        include("$ENV{GEODE_SDK}/Geode.cmake")
    elseif(EXISTS "${CMAKE_SOURCE_DIR}/geode-sdk-clone/Geode.cmake")
        include("${CMAKE_SOURCE_DIR}/geode-sdk-clone/Geode.cmake")
    elseif(EXISTS "$ENV{GITHUB_WORKSPACE}/geode-sdk-clone/Geode.cmake")
        include("$ENV{GITHUB_WORKSPACE}/geode-sdk-clone/Geode.cmake")
    else()
        message(FATAL_ERROR "No se pudo encontrar Geode.cmake en ninguna ruta conocida.")
    endif()
endif()
