# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT rswaveforms_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT rswaveforms_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND rswaveforms_python_files
    smu_waveform_sink_python.cc python_bindings.cc)

gr_pybind_make_oot(rswaveforms ../../.. gr::rswaveforms "${rswaveforms_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET rswaveforms_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:rswaveforms_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/rswaveforms/)

install(
    TARGETS rswaveforms_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/rswaveforms
    COMPONENT pythonapi)
