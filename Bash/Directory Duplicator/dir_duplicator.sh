# Student Name 		: Ee En Goh
# Student Number	: 17202691
# Email				: ee.goh@ucdconnect.ie
# Note				: Execute this script file in terminal with exactly 2 arguments, which is the name of source directory and destination directory, that will duplicate the directories and png-format image files (convert to jpeg file) to the destination directory
	


#! /bin/bash

# 2 arguments expected : ./program_name source_dir destionation_dir

# Check error 1 : invalid numbers of arguments given
if [ ! $# -eq 2 ];
	then echo "Invalid number of arguments given"
	exit
fi

# Check error 2 : Given source file doesn't exist
if [ ! -e $1 ];
	then echo "Error : The given source file doesn't exist"
	exit
fi

function directory {

	for i in `dir $1`
	do
		# if given $2 file doesn't exist, create it as a parent dir 
		if [ ! -e $2 ];
		then
			mkdir $2 
		fi
		
		# If PNG file is found in $1/$i directory
		# Copy it to the duplicate directory
		# File convert needed
		if [[ $(file -b $1/$i) =~ PNG ]]; 
		then
			cp $1/$i $2/$i; 		# Copy the PNG images
			jpeg_file=${png_file/png/jpg} 	# Substring replacement
			mogrify -format jpg $2/$i 	# Convert given png file to jpeg format, while original png file remains
			rm $2/$i			# Move original png file
		fi

		# if there is a directory inside the current directory 
		# Create the same directory and search inside the directory
		if [ -d $1/$i ];
		then
			if [ ! -e $2/$i ];		# If the destination file is not exist : Create a new dir
			then
				mkdir $2/$i
			else
				if [ ! -w $2/$i ];	# If the destination file exist but can't be overwritten : exit
				then
					echo "Error : The destination file can't be overwritten"
					exit
				else			# Else overwrite the directory : Remove the old dir and replace with an empty directory
					rm -r $2/$i
					mkdir $2/$i
				fi
			fi
			directory $1/$i $2/$i 		# Recursive call
		fi
	done
}

directory $1 $2
