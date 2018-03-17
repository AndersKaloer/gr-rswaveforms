/* -*- c++ -*- */

#define RSWAVEFORMS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "rswaveforms_swig_doc.i"

%{
#include "rswaveforms/smu_waveform_sink.h"
%}


%include "rswaveforms/smu_waveform_sink.h"
GR_SWIG_BLOCK_MAGIC2(rswaveforms, smu_waveform_sink);
