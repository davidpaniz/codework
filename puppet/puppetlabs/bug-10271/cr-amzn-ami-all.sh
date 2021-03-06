
ec2-create() {
    echo "Creating ${1}${2}: $6"
    ec2-run-instances --region ${1} -z ${1}${2} -g ${3} -k ${4} -t ${5} ${6} \
    | tee -a $CREATED \
    | gawk '{print strftime("%Y-%m-%d %H:%M:%S :", systime()), $0 }' >> $LOG
#   echo "Sleeping...."
#   sleep 45
}

CREATED="created.txt"
    LOG="actions.log"

REGION="us-east-1"
  TYPE="t1.micro"
 GROUP="server"
   KEY="marcus_anirul"

# Init all files
echo "## $(date)" > $CREATED
> list-instance.txt
> list-ip.txt
> server.rb
> terminate.sh

# create
ec2-create $REGION c $GROUP $KEY $TYPE ami-0af30663  # amzn-ami-0.9.7-beta.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-38c33651  # amzn-ami-0.9.8-beta.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-2272864b  # amzn-ami-0.9.9-beta.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-74f0061d  # amzn-ami-2010.11.1-beta.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-8e1fece7  # amzn-ami-2011.02.1.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-7341831a  # amzn-ami-2011.09.1.x86_64-ebs
ec2-create $REGION c $GROUP $KEY $TYPE ami-1b814f72  # amzn-ami-2011.09.2.x86_64-ebs

## ec2-describe-instances --region us-east-1 | grep running > $CREATED

# Support files
awk '/INSTANCE/ {print $2}' $CREATED                  >> list-instance.txt
awk '/INSTANCE/ {print $4}' $CREATED | grep amazonaws >> list-ip.txt

# to be used by Capfile
awk '{print "server \""$0"\" , :ec2"}' list-ip.txt | column -t> server.rb

# to terminate it all
awk '{print "ec2-terminate-instances --region REGION ", $0}' list-instance.txt > terminate.sh
perl -pi -e "s/REGION/$REGION/" terminate.sh


