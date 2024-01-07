/* -*- c++ -*- */
/*
 * Copyright 2018 Anders Kalør <anders@kaloer.com>.
 * Copyright 2023 Derek Kozel <dkozel@bitstovolts.com>.
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
 * \brief A File Sink block for Rohde & Schwarz SMU Waveform files
 * \ingroup rswaveforms
 *
 */
class RSWAVEFORMS_API smu_waveform_sink : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<smu_waveform_sink> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of
     * rswaveforms::smu_waveform_sink.
     *
     * \param filename Name and path of the file to write
     * \param sample_rate Sample rate of the waveform in Hertz
     */
    static sptr make(const char* filename, unsigned int sample_rate);
};

} // namespace rswaveforms
} // namespace gr

#endif /* INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_H */
