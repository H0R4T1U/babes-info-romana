'''
Created on 8 dec. 2014

@author: teo
'''

class Film():
    '''
    entitatea Film care contine id-ul, titlul, pretul si numarul de locuri rezervate pentru filmul respectiv
    '''
    
    def __init__(self, id, titlu, pret, nrLocuri):
        self.__id = id
        self.__titlu = titlu
        self.__pret = pret
        self.__nrLocuriRez = nrLocuri
        
    
    def getID(self):
        return self.__id
    
    def getTitlu(self):
        return self.__titlu
    
    def getPret(self):
        return self.__pret
    
    def getNrLocuri(self):
        return self.__nrLocuriRez
    
    def setTitlu(self, titlu):
        self.__titlu = titlu
        
    def setNrLocuri(self, nrLocuri):
        self.__nrLocuriRez = nrLocuri
    
    def setPret(self, pret):
        self.__pret = pret
        
    
    def __eq__(self, other):
        '''
        overload-uim operatorul == pentru a verifica daca obiectele sunt identice
        other - alt obiect de tip film
        returneaza True daca obiectele sunt identice si Flase altfel
        '''
        return self.__id == other.getID() and self.__pret == other.getPret() and self.__titlu == other.getTitlu()\
             and self.__nrLocuriRez == other.getNrLocuri()
     
    


def testCreareFilm():
    fi = Film(47, 'De la specii', 15, 68)
    
    assert fi == Film(47, 'De la specii', 15, 68)
    
testCreareFilm()