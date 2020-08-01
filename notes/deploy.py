import os

CLOUD = os.getenviron("CLOUD")

with open('./index.md', 'w') as IndexF:
    IndexF.write("## CP\n")
    for filename in os.listdir("."):
        if filename[-4:] == "html" :
            IndexF.write("* [{}](./{})\n".format(filename.replace("_", " ")[:-5].title(), filename))

if LOCAL:
    for filename in os.listdir("."):
        if filename[-2:] == "md":
            os.system("rm .")