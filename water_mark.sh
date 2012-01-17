foreach()
{
	for file in $1/*
	do
	if [ -d $file ] 
	   then
		echo "enter directory"
		foreach $file
	   else
		addInfo $file
	fi
	echo $file
	done
}
addInfo()
{
cp $1 tmpfile
cat legal_information tmpfile > $1
rm tmpfile
}
for file in *
do
	if [ -d $file ]
	then
		foreach $file
	fi
done
exit 0
