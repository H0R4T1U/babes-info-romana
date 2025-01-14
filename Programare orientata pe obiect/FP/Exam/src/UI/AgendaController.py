from Repository.ContactRepository import *

class AgendaController:
    def __init__(self):
        pass
    def returnAll(self):
        """
            Returns all the contacts
        """
        cr=ContactRepository()
        return cr.getAll()
    def addContact(self,id,name,phoneNr,group):
        """
            Add a new contact to the database
            id is the contact's id
            name is the contact's name
            phoneNr id the contact's phone number
            group is the contacts group
            raise ValueError if the contact is not valid
        """
        cr=ContactRepository()
        try:
            cr.add(Contact(id,name,phoneNr,group))
        except ValueError:
            return False
    def lookup(self,name):
        """
            Look up for a contact by name
            return the contact if found
        """
        cr=ContactRepository()
        return cr.find(name)
    def lookUpAll(self,group):
        """
            Show all the contacts from a group
            group is the group's name
            the return is the list of the group members
        """
        cr=ContactRepository()
        return cr.getAllGr(group)
    def exportCSV(self,group,outFile):
        """
            Export all the group members to a text file
            group is a contact group chosen by the user
            outFile is the output file where the members will appear, separated by comma
        """
        f=open(outFile,'w')
        cr=ContactRepository()
        list=cr.getAllGr(group)
        for i in list:
            x=i.getName()+','+i.getPhoneNr()
            f.write(x)
            f.write('\n')
        f.close()


def testAgendaController():
    ac=AgendaController()
    assert ac.addContact(2,'Name','0740','group')==False
    assert ac.addContact(3,'Name3','vrv','Family')==False
    assert ac.addContact(3,'Name3','0123','gr')==False
    ac.lookup('Name')
    ac.lookUpAll('group')
    list=ac.returnAll()

testAgendaController()
