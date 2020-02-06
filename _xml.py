import xml.etree.ElementTree as e

data = e.parse('_resource/browserstack.xml').getroot()

for i in data.findall('sum'):
  for j in i:
    print(j.get('elem'))