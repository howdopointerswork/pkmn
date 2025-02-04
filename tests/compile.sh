#!/bin/bash

read -p "Enter file name (include extension): " FILE
OS=$(uname -s)

case "$FILE" in
	*.cpp)
		echo "File Type: C++"
		g++ -std=c++11 $FILE
		./a.out
	;;

	*.py)
		echo "File Type: Python"
		python3 $FILE
	;;

	*.java)
		
		echo "File Type: Java"
		javac $FILE
		java $FILE
	;;

	*.html)
		echo "File Type: HTML/CSS/JS"
		if [ "$OS" = Linux ]; then
			xdg-open $FILE
		else
			open $FILE
		fi
		

	;;	
esac
#Trying out env variables
export LAST=$FILE
