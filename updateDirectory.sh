
for dir in $*
do
git rm -r $dir
cp -R /c/Users/dura/Documents/cocos2d-1.0.1-x-0.10.0/HelloWorld/Classes/$dir \
   $dir
   done
