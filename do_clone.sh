cp -R Cocos/UIKit/  kinect/trunk/
cp -R Cocos/Cocos/ kinect/trunk/
cp -R Cocos/Quartz/ kinect/trunk/
cp /c/Users/dura/Documents/cocos2d-1.0.1-x-0.10.0/HelloWorld/Classes/*  \
	kinect/trunk
cp /c/Users/dura/Documents/cocos2d-1.0.1-x-0.10.0/HelloWorld/win32/* \
	kinect/trunk
#svn import --message "checkin" kinect https://test.weibohuan.com:8443/svn/repos/california/kinect
cd kinect
#svn up
#svn commit --message "commit"
