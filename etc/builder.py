from iocbuilder import AutoSubstitution, Device
from iocbuilder.modules.streamDevice import AutoProtocol
from genSub import GenSub

class OXCS700Lib(Device):
    LibFileList=["OXCS700"]
    DbdFileList=["OXCS700Support"]
    AutoInstantiate=True

class OXPH700(AutoSubstitution, AutoProtocol, Device):
    Dependencies = (GenSub, OXCS700Lib)
    # Substitution attributes
    TemplateFile = 'OXPH700.template'

    # AutoProtocol attributes
    ProtocolFiles = ['OXCS700.proto']


class OXCS700(AutoSubstitution, AutoProtocol, Device):
    Dependencies = (GenSub, OXCS700Lib)
    # Substitution attributes
    TemplateFile = 'OXCS700.template'

    # AutoProtocol attributes
    ProtocolFiles = ['OXCS700.proto']


