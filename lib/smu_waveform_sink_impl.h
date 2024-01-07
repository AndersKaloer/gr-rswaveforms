/* -*- c++ -*- */
/*
 * Copyright 2018 Anders Kalør <anders@kaloer.com>.
 * Copyright 2023 Derek Kozel <dkozel@bitstovolts.com>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H
#define INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H

#include <gnuradio/rswaveforms/smu_waveform_sink.h>
#include <cstdint>

#if ULONG_MAX <= 4294967295UL
#define ULONG_MAX_LEN 10
#elif ULONG_MAX <= 18446744073709551615ULL
#define ULONG_MAX_LEN 20
#endif

namespace gr {
namespace rswaveforms {

class smu_waveform_sink_impl : public smu_waveform_sink
{
private:
    FILE* d_fp = NULL;
    unsigned int d_f_level_offs_field_width = 8;
    unsigned int d_f_level_offs_field_prec = 6;
    unsigned int d_f_samples_field_width = ULONG_MAX_LEN;
    unsigned int d_f_waveform_field_width = ULONG_MAX_LEN;
    unsigned int d_f_level_offs_pos = 0;
    unsigned int d_f_samples_pos = 0;
    unsigned int d_f_waveform_pos = 0;
    float d_peak_power_dBfs = 0.0f;
    float d_acc_power = 0.0f;
    unsigned long d_num_samples = 0.0;
    unsigned int d_sample_rate = 0.0;
    float* d_float_buf = NULL;
    uint16_t* d_uint16_buf = NULL;
    float* d_float_arr_buf = NULL;
    int16_t* d_i_buf = NULL;
    int16_t* d_q_buf = NULL;
    int d_alloc_buf_size = 0;

protected:
    void open_file(const char* filename);
    void write_header();
    void update_header(float rms, float peak, int num_samples);
    void write_samples(const gr_complex* data, int len);
    void close_file();
    void wav_write_sample(FILE* fp, short int sample, int bytes_per_sample);

public:
    smu_waveform_sink_impl(const char* filename, unsigned int sample_rate);
    ~smu_waveform_sink_impl();

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace rswaveforms
} // namespace gr

#endif /* INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H */
