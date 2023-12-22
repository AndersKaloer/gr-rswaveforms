find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_RSWAVEFORMS gnuradio-rswaveforms)

FIND_PATH(
    GR_RSWAVEFORMS_INCLUDE_DIRS
    NAMES gnuradio/rswaveforms/api.h
    HINTS $ENV{RSWAVEFORMS_DIR}/include
        ${PC_RSWAVEFORMS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_RSWAVEFORMS_LIBRARIES
    NAMES gnuradio-rswaveforms
    HINTS $ENV{RSWAVEFORMS_DIR}/lib
        ${PC_RSWAVEFORMS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-rswaveformsTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_RSWAVEFORMS DEFAULT_MSG GR_RSWAVEFORMS_LIBRARIES GR_RSWAVEFORMS_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_RSWAVEFORMS_LIBRARIES GR_RSWAVEFORMS_INCLUDE_DIRS)
