/* -*- c++ -*- */
/* 
 * Copyright 2018 Anders Kalør <anders@kaloer.com>
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

#ifndef INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H
#define INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H

#include <rswaveforms/smu_waveform_sink.h>
#include <cstdint>

namespace gr {
  namespace rswaveforms {

    class smu_waveform_sink_impl : public smu_waveform_sink
    {
     private:
      const char *d_filename;
      unsigned int d_sample_rate;
      std::vector<gr_complex> d_buf;

     public:
      smu_waveform_sink_impl(const char *filename, unsigned int sample_rate);
      ~smu_waveform_sink_impl();

      void write_file();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace rswaveforms
} // namespace gr

#endif /* INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H */

