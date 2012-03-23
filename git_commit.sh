git rm *~
git rm *.sh
git add *
git commit -m $(date +%d)
git push origin master
