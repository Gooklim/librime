// vim: set sts=2 sw=2 et:
// encoding: utf-8
//
// Copyleft 2011 RIME Developers
// License: GPLv3
//
// 2011-07-10 GONG Chen <chen.sst@gmail.com>
//
#ifndef RIME_TABLE_TRANSLATOR_H_
#define RIME_TABLE_TRANSLATOR_H_

#include <string>
#include <rime/common.h>
#include <rime/config.h>
#include <rime/translator.h>
#include <rime/algo/algebra.h>
#include <rime/impl/translator_commons.h>

namespace rime {

class Dictionary;
class UserDictionary;

class TableTranslator : public Translator, Memory {
 public:
  TableTranslator(Engine *engine);
  virtual ~TableTranslator();

  virtual shared_ptr<Translation> Query(const std::string &input,
                                        const Segment &segment,
                                        std::string* prompt);
  virtual bool Memorize(const DictEntry& commit_entry,
                        const std::vector<const DictEntry*>& elements);
  

  shared_ptr<Translation> MakeSentence(const std::string &input,
                                       size_t start);

  Dictionary* dict() { return dict_.get(); }
  Projection& comment_formatter() { return comment_formatter_; }
  
 protected:
  std::string delimiters_;
  bool enable_completion_;
  bool enable_charset_filter_;
  
  Projection preedit_formatter_;
  Projection comment_formatter_;
  Patterns user_dict_disabling_patterns_;
};

}  // namespace rime

#endif  // RIME_TABLE_TRANSLATOR_H_
