# Python program to download audio from Youtube
# FFmpeg : A free software project online for handling multimedia files and streams
# Online library documentation : https://github.com/ytdl-org/youtube-dl/blob/3e4cedf9e8cd3157df2457df7274d0c842421945/youtube_dl/YoutubeDL.py#L137-L312 

from __future__ import unicode_literals
import youtube_dl

class MyLogger(object):

    def debug(self, msg):
        pass # It means continue in Python

    def warning(self, msg):
        pass
    
    def error(self, msg):  # Display only when there are error while downloading 
        print(msg)

# Message output after the download is done
def my_hook(d):
    if d['status'] == 'finished' :
        print('Download done, now converting ...')


# Setup the audio format and stuff
ydl_opts = {
    # format : video format code 
    'format' : 'bestaudio/best',        

    # postprocessor : A list of dictionaries with an entry
    'postprocessor' : [{
        'key' : 'FFmpegExtractAudio',   # Name of the postprocessor
        'preferredcodec' : 'mp3',       # Audio format  
        'preferredquality' : '192', 
    }],
    'postprocessor_args' : [
        '-ar','16000'
    ],
    
    'logger' : MyLogger(),  # A library object that used to intercept youtube-dl's output
    'progress_hooks' : [my_hook],
    'prefer_ffmpeg' : True, # Post-processors option : use ffmpeg instead of avconv if both are available
    'keepvideo' : True,     # Keep the video file after post-processing
    'noplaylist' : True     # Download a single video instead of a playlist if playlist URLL given
}
with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    ydl.download(['https://www.youtube.com/watch?v=TcOWwIQDpnE'])
