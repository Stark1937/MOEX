//
// Created by everettjf on 2017/3/31.
//

#ifndef MACHOEXPLORER_LOADCOMMAND_LOAD_DYLINKER_H
#define MACHOEXPLORER_LOADCOMMAND_LOAD_DYLINKER_H

#include "loadcommand.h"

MOEX_NAMESPACE_BEGIN

class LoadCommand_LC_LOAD_DYLINKER : public LoadCommandImpl<dylinker_command>{
private:
    std::string dylinker_path_name_;
public:
    const std::string & dylinker_path_name()const{return dylinker_path_name_;}

    void init(void * offset,NodeContextPtr & ctx)override {
        LoadCommandImpl::init(offset,ctx);

        dylinker_path_name_ = reinterpret_cast<char*>((char*)offset_ + cmd_->name.offset);
    }
    std::string GetTypeName() override{ return "dylinker_command";}
    std::string GetDisplayName() override{ return "dylinker";}
    std::string GetDescription() override{
        return boost::str(boost::format("%1%(type=%2%,size=%3%,dylinker path name=%4%)")
                          % this->GetDisplayName()
                          % hp::GetLoadCommandType(offset_->cmd)
                          % offset_->cmdsize
                          % dylinker_path_name_
        );
    }
};


MOEX_NAMESPACE_END

#endif //MACHOEXPLORER_LOADCOMMAND_LOAD_DYLINKER_H
