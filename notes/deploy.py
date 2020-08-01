import os

CLOUD = os.environ["CLOUD"]

with open('./index.md', 'w') as IndexF:
    IndexF.write("## CP\n")
    for filename in os.listdir("."):
        if filename[-4:] == "html" :
            IndexF.write("* [{}](./{})\n".format(filename.replace("_", " ")[:-5].title(), filename))

if CLOUD:
    for filename in os.listdir("."):
        if filename[-2:] == "md":
            os.system("rm .")