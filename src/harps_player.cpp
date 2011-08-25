/***************************************************************************
 *   Copyright (C) 2009 by Naomasa Matsubayashi   *
 *   harps@quaternion.sakura.ne.jp   *
 *                                                                         *
 *   All rights reserved.                                                  *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *   modification, are permitted provided that the following conditions    *
 *   are met:                                                              *
 *     * Redistributions of source code must retain the above copyright    *
 *       notice, this list of conditions and the following disclaimer.     *
 *     * Redistributions in binary form must reproduce the above copyright *
 *       notice, this list of conditions and the following disclaimer in   *
 *       the documentation and/or other materials provided with the        *
 *       distribution.                                                     *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR *
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 *   OWNER OR                                                              *
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, *
 *   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,   *
 *   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR    *
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY   *
 *   OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE *
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *
 ***************************************************************************/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <harps/instrument.hpp>
#include <harps/buffer.hpp>
#include <harps/output/alsa.hpp>
#include <harps/output/wave.hpp>
#include <harps/input/simple.hpp>
#include <harps/compornent/dynamic_module.hpp>
#include <harps/normalize.hpp>

#include <score.hpp>

int main(int argc, char *argv[]) {
  using namespace harps;
  using namespace tbb;
/*  input::Tracks<
    output::Wave< false, 2 >,
    input::SimpleReader< DynamicPolyphony< DynamicMonophony, 64 > >,
    Buffer< float >,
    2 > tracks( "test3.wav" );*/
  input::Tracks<
    output::ALSA< false, 2 >,
    input::SimpleReader< DynamicPolyphony< DynamicMonophony, 64 > >,
    Buffer< float >,
    2 > tracks( "hw:0" );
  tracks.setScore( 0, "/harps/electric_piano.so", score0 );
  tracks.setScore( 1, "/harps/strings.so", score1 );
  while( !tracks.isEnd() ) {
    tracks();
  }
  return EXIT_SUCCESS;
}
