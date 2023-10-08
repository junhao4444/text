//
// Generated file, do not edit! Created by nedtool 5.5 from veins/modules/application/traci/BeaconRSU.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "BeaconRSU_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace veins {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(BeaconRSU)

BeaconRSU::BeaconRSU(const char *name, short kind) : ::veins::BaseFrame1609_4(name,kind)
{
    this->RSUId = 0;
    for (unsigned int i=0; i<100; i++)
        this->beaconrate[i] = 0;
    this->timestamp = 0;
}

BeaconRSU::BeaconRSU(const BeaconRSU& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

BeaconRSU::~BeaconRSU()
{
}

BeaconRSU& BeaconRSU::operator=(const BeaconRSU& other)
{
    if (this==&other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void BeaconRSU::copy(const BeaconRSU& other)
{
    this->RSUId = other.RSUId;
    for (unsigned int i=0; i<100; i++)
        this->position[i] = other.position[i];
    for (unsigned int i=0; i<100; i++)
        this->beaconrate[i] = other.beaconrate[i];
    this->myDemoData = other.myDemoData;
    this->slotpos = other.slotpos;
    this->timestamp = other.timestamp;
}

void BeaconRSU::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->RSUId);
    doParsimArrayPacking(b,this->position,100);
    doParsimArrayPacking(b,this->beaconrate,100);
    doParsimPacking(b,this->myDemoData);
    doParsimPacking(b,this->slotpos);
    doParsimPacking(b,this->timestamp);
}

void BeaconRSU::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->RSUId);
    doParsimArrayUnpacking(b,this->position,100);
    doParsimArrayUnpacking(b,this->beaconrate,100);
    doParsimUnpacking(b,this->myDemoData);
    doParsimUnpacking(b,this->slotpos);
    doParsimUnpacking(b,this->timestamp);
}

int BeaconRSU::getRSUId() const
{
    return this->RSUId;
}

void BeaconRSU::setRSUId(int RSUId)
{
    this->RSUId = RSUId;
}

unsigned int BeaconRSU::getPositionArraySize() const
{
    return 100;
}

Coord& BeaconRSU::getPosition(unsigned int k)
{
    if (k>=100) throw omnetpp::cRuntimeError("Array of size 100 indexed by %lu", (unsigned long)k);
    return this->position[k];
}

void BeaconRSU::setPosition(unsigned int k, const Coord& position)
{
    if (k>=100) throw omnetpp::cRuntimeError("Array of size 100 indexed by %lu", (unsigned long)k);
    this->position[k] = position;
}

unsigned int BeaconRSU::getBeaconrateArraySize() const
{
    return 100;
}

double BeaconRSU::getBeaconrate(unsigned int k) const
{
    if (k>=100) throw omnetpp::cRuntimeError("Array of size 100 indexed by %lu", (unsigned long)k);
    return this->beaconrate[k];
}

void BeaconRSU::setBeaconrate(unsigned int k, double beaconrate)
{
    if (k>=100) throw omnetpp::cRuntimeError("Array of size 100 indexed by %lu", (unsigned long)k);
    this->beaconrate[k] = beaconrate;
}

const char * BeaconRSU::getMyDemoData() const
{
    return this->myDemoData.c_str();
}

void BeaconRSU::setMyDemoData(const char * myDemoData)
{
    this->myDemoData = myDemoData;
}

Coord& BeaconRSU::getSlotpos()
{
    return this->slotpos;
}

void BeaconRSU::setSlotpos(const Coord& slotpos)
{
    this->slotpos = slotpos;
}

::omnetpp::simtime_t BeaconRSU::getTimestamp() const
{
    return this->timestamp;
}

void BeaconRSU::setTimestamp(::omnetpp::simtime_t timestamp)
{
    this->timestamp = timestamp;
}

class BeaconRSUDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BeaconRSUDescriptor();
    virtual ~BeaconRSUDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BeaconRSUDescriptor)

BeaconRSUDescriptor::BeaconRSUDescriptor() : omnetpp::cClassDescriptor("veins::BeaconRSU", "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

BeaconRSUDescriptor::~BeaconRSUDescriptor()
{
    delete[] propertynames;
}

bool BeaconRSUDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BeaconRSU *>(obj)!=nullptr;
}

const char **BeaconRSUDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BeaconRSUDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BeaconRSUDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int BeaconRSUDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *BeaconRSUDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "RSUId",
        "position",
        "beaconrate",
        "myDemoData",
        "slotpos",
        "timestamp",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int BeaconRSUDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RSUId")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "position")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconrate")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "myDemoData")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "slotpos")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BeaconRSUDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "Coord",
        "double",
        "string",
        "Coord",
        "simtime_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **BeaconRSUDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BeaconRSUDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BeaconRSUDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BeaconRSU *pp = (BeaconRSU *)object; (void)pp;
    switch (field) {
        case 1: return 100;
        case 2: return 100;
        default: return 0;
    }
}

const char *BeaconRSUDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BeaconRSU *pp = (BeaconRSU *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BeaconRSUDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BeaconRSU *pp = (BeaconRSU *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getRSUId());
        case 1: {std::stringstream out; out << pp->getPosition(i); return out.str();}
        case 2: return double2string(pp->getBeaconrate(i));
        case 3: return oppstring2string(pp->getMyDemoData());
        case 4: {std::stringstream out; out << pp->getSlotpos(); return out.str();}
        case 5: return simtime2string(pp->getTimestamp());
        default: return "";
    }
}

bool BeaconRSUDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BeaconRSU *pp = (BeaconRSU *)object; (void)pp;
    switch (field) {
        case 0: pp->setRSUId(string2long(value)); return true;
        case 2: pp->setBeaconrate(i,string2double(value)); return true;
        case 3: pp->setMyDemoData((value)); return true;
        case 5: pp->setTimestamp(string2simtime(value)); return true;
        default: return false;
    }
}

const char *BeaconRSUDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Coord));
        case 4: return omnetpp::opp_typename(typeid(Coord));
        default: return nullptr;
    };
}

void *BeaconRSUDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BeaconRSU *pp = (BeaconRSU *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPosition(i)); break;
        case 4: return (void *)(&pp->getSlotpos()); break;
        default: return nullptr;
    }
}

} // namespace veins

