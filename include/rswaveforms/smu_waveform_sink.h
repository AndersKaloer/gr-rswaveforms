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


#ifndef INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H
#define INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H

#include <rswaveforms/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace rswaveforms {

    /*!
     * \brief <+description of block+>
     * \ingroup rswaveforms
     *
     */
    class RSWAVEFORMS_API smu_waveform_sink : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<smu_waveform_sink> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of rswaveforms::smu_waveform_sink.
       *
       * To avoid accidental use of raw pointers, rswaveforms::smu_waveform_sink's
       * constructor is in a private implementation
       * class. rswaveforms::smu_waveform_sink::make is the public interface for
       * creating new instances.
       */
      static sptr make(const char *filename, unsigned int sample_rate);
    };

  } // namespace rswaveforms
} // namespace gr

#endif /* INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H */

