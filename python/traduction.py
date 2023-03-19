from translate import Translator


class ArreraTrad : 
    def __init__(self,langueInt,langueOut):
        self.traducteur = Translator(from_lang=langueInt,to_lang=langueOut)
        
    def Tradution(text):
        return self.traducteur.translate(str(text))



