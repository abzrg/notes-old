## how to hard sub a mkv video that has a soft sub with ffmpeg?

To hardcode (or "burn in") subtitles onto a video using FFmpeg, you can use the
subtitles filter. Here's an example command to hardcode a soft subtitle track
onto a video:

```sh
ffmpeg -i input.mkv -vf subtitles=input.mkv output.mp4
```

This command assumes that the subtitle track you want to hardcode is the first
subtitle track in the `input.mkv` file. If you want to select a different subtitle
track, you can use the `-map` option followed by the stream specifier for the
subtitle track.

For example, if you want to hardcode the second subtitle track, you can use the
following command:

```sh
ffmpeg -i input.mkv -vf subtitles=input.mkv:si=1 output.mp4
```

This command uses the `si` option to specify the subtitle track index (starting
from `0`), which in this case is `1` for the second subtitle track.

Note that the output file format doesn't have to be MP4; you can use any format
that FFmpeg supports.


## this uses all the available cores. how tell ffmpeg to use one core

By default, FFmpeg will use all available CPU cores to speed up the encoding
process. If you want to limit FFmpeg to use only one core, you can use the
`-threads` option to set the number of threads to use for encoding.

For example, to limit FFmpeg to use only one thread, you can use the following
command:

```sh
ffmpeg -i input.mkv -vf subtitles=input.mkv -threads 1 output.mp4
```
This command sets the number of threads to `1` using the `-threads` option. This
will cause FFmpeg to use only one CPU core for encoding, which may slow down the
encoding process but can be useful in some situations where you want to limit
CPU usage.

Note that the `-threads` option can also be used to set the number of threads to
use for decoding and other tasks in FFmpeg. You can specify different numbers of
threads for different tasks using separate `-threads` options.



## what if the video does not have a soft subtitle and how to provide the subtitle on command line?

If the video doesn't have a soft subtitle, you can add an external subtitle file
to the video using FFmpeg. To do this, you can use the `-i` option to specify the
input video file and the `-i` option again to specify the external subtitle file.

Here's an example command to add an external subtitle file to a video:

```sh
ffmpeg -i input.mp4 -i subtitles.srt -map 0:v -map 0:a -map 1:s -c:v copy -c:a copy -c:s mov_text output.mp4
```
This command assumes that the subtitle file is in the SubRip format (`.srt`). If
your subtitle file is in a different format, you may need to specify the format
using the `-f` option.

You can also specify the subtitle file on the command line using the `-vf` option
with the subtitles filter. Here's an example command to add a subtitle file to
a video using the subtitles filter:

```sh
ffmpeg -i input.mp4 -vf subtitles=subtitles.srt output.mp4
```
This command assumes that the subtitle file is in the same directory as the
input video file. If your subtitle file is in a different directory, you'll need
to specify the full path to the file.

Note that in both examples, the output video file format is set to mp4 using the
`-c:v copy -c:a copy -c:s mov_text` options. You can change the output format to
any format that FFmpeg supports by specifying the appropriate video and audio
codecs.


## what if the subtitle has a delay

If the subtitle has a delay, you can adjust the subtitle timing using the
subtitles filter in FFmpeg. The subtitles filter has several options for
adjusting the subtitle timing, including the delay option.

Here's an example command to add a subtitle file with a delay of 2 seconds to
a video:

```sh
ffmpeg -i input.mp4 -vf subtitles=subtitles.srt:delay=2 output.mp4
```

This command adds the subtitle file `subtitles.srt` to the video and sets
a delay of 2 seconds using the delay option. The output video file will have the
subtitle displayed 2 seconds later than the original timing in the subtitle
file.

You can adjust the delay time by changing the value of the delay option to
a different number of seconds. Positive values will delay the subtitle timing,
while negative values will advance the subtitle timing.

Note that the delay option can be used together with other subtitles filter
options to adjust the subtitle appearance and placement, such as the `fontfile`,
`fontsize`, `bordercolor`, and `boxcolor` options. You can find more information
about these options in the FFmpeg documentation.
