from iocbuilder import AutoSubstitution
from iocbuilder.modules.streamDevice import AutoProtocol

class OXPH700(AutoSubstitution, AutoProtocol):
    # Substitution attributes
    TemplateFile = 'OXPH700.template'

    # AutoProtocol attributes
    ProtocolFiles = ['OXCS700.proto']


class OXCS700(AutoSubstitution, AutoProtocol):
    # Substitution attributes
    TemplateFile = 'OXCS700.template'

    # AutoProtocol attributes
    ProtocolFiles = ['OXCS700.proto']


