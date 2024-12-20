#!/bin/bash
read dway 
read rash
while [ -z $dway ] || [[ -z $rash ]]
    do
        echo "введите директорию и разрешение"
        read dway 
        read rash
done
if ! [ -d $dway ]
    then
        echo "нет такой директории"
    else
       files = $ find $dway - name "*.$rash"
       if [ -z $files]; then
        echo "файлы с расширением $rash не найдены"
        else
            echo files
        fi
        
fi
