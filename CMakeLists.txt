#files

file(GLOB EssexEngineAppEditor_HEADERS
    "src/Apps/Editor/*.h"
    "src/Apps/Editor/Windows/*.h"
)
file(GLOB EssexEngineAppEditor_SRC
    ${EssexEngineAppEditor_HEADERS}
    "src/Apps/Editor/*.cpp"
    "src/Apps/Editor/Windows/*.cpp"
)

#setup headers

file(COPY ${EssexEngineAppEditor_HEADERS} DESTINATION "${CMAKE_BINARY_DIR}/lib/include/EssexEngineAppEditor/")

#setup build

add_library(EssexEngineAppEditor SHARED ${EssexEngineAppEditor_SRC})
target_link_libraries(EssexEngineAppEditor EssexEngineCore)
target_link_libraries(EssexEngineAppEditor EssexEngineLibIsoMap)
target_link_libraries(EssexEngineAppEditor EssexEngineJsonDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineFileSystemDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineInputDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineWindowDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineAppGame)

#run

add_custom_target(runEditor
    COMMAND EssexEngineBootloader --editor
    DEPENDS EssexEngineBootloader
    WORKING_DIRECTORY ../filesystem
)