import holidays
import datetime
import json
from travailJSON import*

class Calendrier :
    def __init__(self):
        self.anneeEnCours = str(datetime.date.today().year)
        self.moisEnCours = str(datetime.date.today().month)
        self.jourEnCours = str(datetime.date.today().day)
        
        
    def SaintDujour(self):
        jourSaint = json.load(open(file="listFete.json", encoding='utf-8'))[self.moisEnCours][self.jourEnCours]
        return str(jourSaint)
    
    def jourFerier(self):
        joursFeries = dict(holidays.FRA(years=datetime.date.today().year))
        if self.anneeEnCours+"-"+self.moisEnCours+"-"+self.jourEnCours in  joursFeries :
            ferier = True 
            nameJour = joursFeries[self.anneeEnCours+"-"+self.moisEnCours+"-"+self.jourEnCours]
        else :
            ferier = False
            nameJour = "none"
            
        return ferier,nameJour
    
class Agenda : 
    def __init__(self,file) :
        self.fichier = file
        
    def addEvent(self,name,day,month,years):
        baseDict = {"name":"","date":""}
        nombre = compteurJSON(self.fichier)
        nombre = nombre + 1
        date = str(years)+"-"+str(month)+"-"+str(day)
        baseDict["name"] = str(name)
        baseDict["date"] = date
        EcritureSansEcrasement(self.fichier, baseDict, str(nombre))
        
    def ListEvent(self):
        nombre = compteurJSON(self.fichier)
        i = 1
        dictEnvent = {}
        while i <= nombre :
            var = lectureJSONDict(self.fichier,str(i))    
            var = var["name"]
            dictEnvent[str(i)] = var  
            i = i + 1
        return dictEnvent
    
    
    def SupprEnvent(self,nbEnvent):
        var = lectureSimpleJSON(self.fichier)
        del var[str(nbEnvent)]
        nouveau_dict = {}
        for i, key in enumerate(var.keys(), start=1):
            nouveau_dict[str(i)] = var[key]
            var = nouveau_dict
        EcritureEcrasement(self.fichier, var)
        