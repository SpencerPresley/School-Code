#!/bin/bash

printf "Enter directory to be searched for file: "
read directory

cd ~

if [[ ! -d $directory ]];then
	printf "Error, could not find the directory."
	exit 1
else
	cd $directory
fi

printf "\n\nEnter file name to be searched for: "
read filename
i=1
while [ $i -le 3 ];do
	if [[ ! -f $filename ]];then
		printf "The file entered ($filename) does not exist. Please try again.\nEnter File Name: "
		read filename
		let "i++"
	else
		break
	fi	
done

if [[ $i -gt 3 ]];then
	printf "No such file exists."
	exit 2
fi

if [[ ! -r $filename ]];then
	printf "File not readable"
	exit 3
fi

printf "Enter word from file: "
read word
printf "$word"

printf "here"

if [ $(grep "$(word)" "$(file)") -eq 1 ];
then
	printf "$word was not found."
else
	printf "$word found."
	exit 4
fi

printf "here"
exit 0
	
