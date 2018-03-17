/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "smu_waveform_sink_impl.h"

namespace gr {
  namespace rswaveforms {

    smu_waveform_sink::sptr
    smu_waveform_sink::make(const char *filename, unsigned int sample_rate, const char *comment)
    {
      return gnuradio::get_initial_sptr
        (new smu_waveform_sink_impl(filename, sample_rate, comment));
    }

    /*
     * The private constructor
     */
    smu_waveform_sink_impl::smu_waveform_sink_impl(const char *filename, unsigned int sample_rate, const char *comment)
      : gr::sync_block("smu_waveform_sink",
              gr::io_signature::make(<+MIN_IN+>, <+MAX_IN+>, sizeof(<+ITYPE+>)),
              gr::io_signature::make(0, 0, 0))
    {}

    /*
     * Our virtual destructor.
     */
    smu_waveform_sink_impl::~smu_waveform_sink_impl()
    {
    }

    int
    smu_waveform_sink_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const <+ITYPE+> *in = (const <+ITYPE+> *) input_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace rswaveforms */
} /* namespace gr */

