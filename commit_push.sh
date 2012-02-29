git add *
git rm classpath
git rm *~
git rm *.sh
git rm log
git commit -m $(date +%d)
git push origin master
