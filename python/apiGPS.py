import requests

class ville:
    def __init__(self,ville):
        url = "http://api.openweathermap.org/geo/1.0/direct?q="
        keyApi=""
        self.reponse = requests.get(url+ville+"&appid="+keyApi)
    def lat(self):#permet de recuperé la latitude
        if self.reponse.status_code == 400 :
            return "error"
        else :
            return str(self.reponse.json()[0]["lat"])
    
    def long(self):#permet de recuperé la longitude
        if self.reponse.status_code == 400 :
            return "error"
        else :
            return str(self.reponse.json()[0]["lon"])