/* -*- c++ -*- */
/*
 * Copyright 2023 gr-rswaveforms author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H
#define INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H

#include <gnuradio/rswaveforms/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace rswaveforms {

/*!
 * \brief <+description of block+>
 * \ingroup rswaveforms
 *
 */
class RSWAVEFORMS_API smu_waveform_sink : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<smu_waveform_sink> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of
   * rswaveforms::smu_waveform_sink.
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
