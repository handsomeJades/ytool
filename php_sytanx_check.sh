STAGE_FILES=$(git diff --cached --name-only --diff-filter=ACM -- '*.php')
if test ${#STAGE_FILES} -gt 0
then
    #echo '---->开始php检查'
    for FILE in $STAGE_FILES
    do
        rs=`php -l $FILE 2>&1`
        cutRs=`echo $rs | cut -c -16`
        if [ "$cutRs" != "No syntax errors" ];then
                echo "---->php语法错误，请修改"
                echo $rs
                exit 1
        fi
    done
fi
#echo '---->php语法检查通过'
exit 0
