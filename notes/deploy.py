import os

os.system("mkdir _build")
os.system("mkdir _build/assets")

os.system("cp -r ./assets ./_build/assets")

for filename in os.listdir("."):
    if filename[-4:] == "html":
        os.system("cp ./{} ./_build".format(filename))


with open('./index.md', 'w') as IndexF:
    for filename in os.listdir("."):
        if filename[-4:] == "html" :
            IndexF.write("* [{}](./{})\n".format(filename.replace("_", " ")[:-5].title(), filename))

os.system("cp ./index.md ./_build")