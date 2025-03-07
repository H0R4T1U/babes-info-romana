'''
Created on Jan 23, 2013

@author: Maria
'''
from Word import Word
class WordValidator:
    def __init__(self):
        pass
    
    def wordempty(self,id,lang,word):
        '''
        checks if the id, language, and word are empty and raises a value error if so
        '''
        errorMsg=""
        if id=="":
            errorMsg+="id can not be empty"
        if lang=="":
            errorMsg+="language can not be empty"
        if word=="":
            errorMsg+="word can not be empty"
        if errorMsg !="":
            raise ValueError(errorMsg)
        
    def goodLanguage(self,lang):
        '''
        raises value error if the language does not exist in the dictionary(Ro,Fr,En)
        '''
        exists=0
        if (lang=="Ro" or lang=="En" or lang=="Fr"):
            exists=1
        if exists==0:
            raise ValueError("not existing language")
    
    def existingword(self,repo,w,lang):
        '''
        checks if there already exists a word for a language
        '''
        words=repo.getAll()
        for i in range(0,len(words)):
            if w==words[i].get_word() and lang==words[i].get_lang():
                raise ValueError("the word exists")    
        
def testValidator():
    val=WordValidator()
    word=Word("","","")
    try:
        val.wordempty(word.get_id(),word.get_lang(),word.get_word())
    except ValueError:
        assert True
        
    word1=Word("1","","")
    try:
        val.wordempty(word1.get_id(),word1.get_lang(),word1.get_word())
    except ValueError:
        assert True    
testValidator()
    