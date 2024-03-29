/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(smu_waveform_sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(6e0ffeb9fe71e24bb51911d63df08afd)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/rswaveforms/smu_waveform_sink.h>
// pydoc.h is automatically generated in the build directory
#include <smu_waveform_sink_pydoc.h>

void bind_smu_waveform_sink(py::module& m)
{

    using smu_waveform_sink = gr::rswaveforms::smu_waveform_sink;


    py::class_<smu_waveform_sink,
               gr::block,
               gr::basic_block,
               std::shared_ptr<smu_waveform_sink>>(
        m, "smu_waveform_sink", D(smu_waveform_sink))

        .def(py::init(&smu_waveform_sink::make),
             py::arg("filename"),
             py::arg("sample_rate"),
             D(smu_waveform_sink, make))


        ;
}
