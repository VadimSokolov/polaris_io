// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef OUT_NETWORK_ODB_HXX
#define OUT_NETWORK_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20100UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "OutNetwork.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/tr1/wrapper-traits.hxx>
#include <odb/tr1/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/buffer.hxx>
#include <odb/details/unused.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // Node
  //
  template <>
  struct class_traits< ::Node >
  {
    static const class_kind kind = class_object;
  };

  template <typename A>
  struct query_columns< ::Node, A >
  {
    // node
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    node_type_;

    static const node_type_ node;

    // x
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    x_type_;

    static const x_type_ x;

    // y
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    y_type_;

    static const y_type_ y;

    // z
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    z_type_;

    static const z_type_ z;

    // subarea
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    subarea_type_;

    static const subarea_type_ subarea;

    // part
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    part_type_;

    static const part_type_ part;
  };

  template <typename A>
  const typename query_columns< ::Node, A >::node_type_
  query_columns< ::Node, A >::
  node (A::table_name, "\"node\"", 0);

  template <typename A>
  const typename query_columns< ::Node, A >::x_type_
  query_columns< ::Node, A >::
  x (A::table_name, "\"x\"", 0);

  template <typename A>
  const typename query_columns< ::Node, A >::y_type_
  query_columns< ::Node, A >::
  y (A::table_name, "\"y\"", 0);

  template <typename A>
  const typename query_columns< ::Node, A >::z_type_
  query_columns< ::Node, A >::
  z (A::table_name, "\"z\"", 0);

  template <typename A>
  const typename query_columns< ::Node, A >::subarea_type_
  query_columns< ::Node, A >::
  subarea (A::table_name, "\"subarea\"", 0);

  template <typename A>
  const typename query_columns< ::Node, A >::part_type_
  query_columns< ::Node, A >::
  part (A::table_name, "\"part\"", 0);

  template <typename A>
  struct pointer_query_columns< ::Node, A >:
    query_columns< ::Node, A >
  {
  };

  template <>
  class access::object_traits< ::Node >
  {
    public:
    typedef ::Node object_type;
    typedef ::std::tr1::shared_ptr< ::Node > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef int id_type;
    static const bool auto_id = false;

    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    static const bool abstract = false;

    struct image_type
    {
      // node
      //
      long long node_value;
      bool node_null;

      // x
      //
      double x_value;
      bool x_null;

      // y
      //
      double y_value;
      bool y_null;

      // z
      //
      double z_value;
      bool z_null;

      // subarea
      //
      long long subarea_value;
      bool subarea_null;

      // part
      //
      long long part_value;
      bool part_null;

      std::size_t version;
    };

    static id_type
    id (const object_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&, bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static void
    bind (sqlite::bind*, id_image_type&);

    static bool
    init (image_type&, const object_type&, sqlite::statement_kind);

    static void
    init (object_type&, const image_type&, database*);

    static void
    init (id_image_type&, const id_type&);

    typedef
    odb::pointer_cache_traits<pointer_type>
    pointer_cache_traits;
    typedef
    odb::reference_cache_traits<object_type>
    reference_cache_traits;

    typedef sqlite::object_statements<object_type> statements_type;

    typedef sqlite::query query_base_type;

    struct container_statement_cache_type;

    static const std::size_t column_count = 6UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static bool
    create_schema (database&, unsigned short pass, bool drop);

    public:
    static bool
    find_ (statements_type&, const id_type*);

    static void
    load_ (statements_type&, object_type&);
  };

  // Link
  //
  template <>
  struct class_traits< ::Link >
  {
    static const class_kind kind = class_object;
  };

  template <typename A>
  struct pointer_query_columns< ::Link, A >
  {
    // link
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    link_type_;

    static const link_type_ link;

    // name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    name_type_;

    static const name_type_ name;

    // node_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    node_a_type_;

    static const node_a_type_ node_a;

    // node_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    node_b_type_;

    static const node_b_type_ node_b;

    // length
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    length_type_;

    static const length_type_ length;

    // setback_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    setback_a_type_;

    static const setback_a_type_ setback_a;

    // setback_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    setback_b_type_;

    static const setback_b_type_ setback_b;

    // bearing_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    bearing_a_type_;

    static const bearing_a_type_ bearing_a;

    // bearing_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    bearing_b_type_;

    static const bearing_b_type_ bearing_b;

    // type
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    type_type_;

    static const type_type_ type;

    // divided
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    divided_type_;

    static const divided_type_ divided;

    // area_type
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    area_type_type_;

    static const area_type_type_ area_type;

    // use
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    use_type_;

    static const use_type_ use;

    // grade
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    grade_type_;

    static const grade_type_ grade;

    // lanes_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    lanes_ab_type_;

    static const lanes_ab_type_ lanes_ab;

    // speed_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    speed_ab_type_;

    static const speed_ab_type_ speed_ab;

    // fspd_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    fspd_ab_type_;

    static const fspd_ab_type_ fspd_ab;

    // cap_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    cap_ab_type_;

    static const cap_ab_type_ cap_ab;

    // lanes_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    lanes_ba_type_;

    static const lanes_ba_type_ lanes_ba;

    // speed_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    speed_ba_type_;

    static const speed_ba_type_ speed_ba;

    // fspd_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    fspd_ba_type_;

    static const fspd_ba_type_ fspd_ba;

    // cap_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    cap_ba_type_;

    static const cap_ba_type_ cap_ba;

    // left_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    left_ab_type_;

    static const left_ab_type_ left_ab;

    // right_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    right_ab_type_;

    static const right_ab_type_ right_ab;

    // left_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    left_ba_type_;

    static const left_ba_type_ left_ba;

    // right_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    right_ba_type_;

    static const right_ba_type_ right_ba;
  };

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::link_type_
  pointer_query_columns< ::Link, A >::
  link (A::table_name, "\"link\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::name_type_
  pointer_query_columns< ::Link, A >::
  name (A::table_name, "\"name\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::node_a_type_
  pointer_query_columns< ::Link, A >::
  node_a (A::table_name, "\"node_a\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::node_b_type_
  pointer_query_columns< ::Link, A >::
  node_b (A::table_name, "\"node_b\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::length_type_
  pointer_query_columns< ::Link, A >::
  length (A::table_name, "\"length\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::setback_a_type_
  pointer_query_columns< ::Link, A >::
  setback_a (A::table_name, "\"setback_a\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::setback_b_type_
  pointer_query_columns< ::Link, A >::
  setback_b (A::table_name, "\"setback_b\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::bearing_a_type_
  pointer_query_columns< ::Link, A >::
  bearing_a (A::table_name, "\"bearing_a\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::bearing_b_type_
  pointer_query_columns< ::Link, A >::
  bearing_b (A::table_name, "\"bearing_b\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::type_type_
  pointer_query_columns< ::Link, A >::
  type (A::table_name, "\"type\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::divided_type_
  pointer_query_columns< ::Link, A >::
  divided (A::table_name, "\"divided\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::area_type_type_
  pointer_query_columns< ::Link, A >::
  area_type (A::table_name, "\"area_type\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::use_type_
  pointer_query_columns< ::Link, A >::
  use (A::table_name, "\"use\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::grade_type_
  pointer_query_columns< ::Link, A >::
  grade (A::table_name, "\"grade\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::lanes_ab_type_
  pointer_query_columns< ::Link, A >::
  lanes_ab (A::table_name, "\"lanes_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::speed_ab_type_
  pointer_query_columns< ::Link, A >::
  speed_ab (A::table_name, "\"speed_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::fspd_ab_type_
  pointer_query_columns< ::Link, A >::
  fspd_ab (A::table_name, "\"fspd_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::cap_ab_type_
  pointer_query_columns< ::Link, A >::
  cap_ab (A::table_name, "\"cap_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::lanes_ba_type_
  pointer_query_columns< ::Link, A >::
  lanes_ba (A::table_name, "\"lanes_ba\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::speed_ba_type_
  pointer_query_columns< ::Link, A >::
  speed_ba (A::table_name, "\"speed_ba\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::fspd_ba_type_
  pointer_query_columns< ::Link, A >::
  fspd_ba (A::table_name, "\"fspd_ba\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::cap_ba_type_
  pointer_query_columns< ::Link, A >::
  cap_ba (A::table_name, "\"cap_ba\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::left_ab_type_
  pointer_query_columns< ::Link, A >::
  left_ab (A::table_name, "\"left_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::right_ab_type_
  pointer_query_columns< ::Link, A >::
  right_ab (A::table_name, "\"right_ab\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::left_ba_type_
  pointer_query_columns< ::Link, A >::
  left_ba (A::table_name, "\"left_ba\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Link, A >::right_ba_type_
  pointer_query_columns< ::Link, A >::
  right_ba (A::table_name, "\"right_ba\"", 0);

  template <>
  class access::object_traits< ::Link >
  {
    public:
    typedef ::Link object_type;
    typedef ::std::tr1::shared_ptr< ::Link > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef int id_type;
    static const bool auto_id = false;

    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    static const bool abstract = false;

    struct image_type
    {
      // link
      //
      long long link_value;
      bool link_null;

      // name
      //
      details::buffer name_value;
      std::size_t name_size;
      bool name_null;

      // node_a
      //
      long long node_a_value;
      bool node_a_null;

      // node_b
      //
      long long node_b_value;
      bool node_b_null;

      // length
      //
      double length_value;
      bool length_null;

      // setback_a
      //
      double setback_a_value;
      bool setback_a_null;

      // setback_b
      //
      double setback_b_value;
      bool setback_b_null;

      // bearing_a
      //
      long long bearing_a_value;
      bool bearing_a_null;

      // bearing_b
      //
      long long bearing_b_value;
      bool bearing_b_null;

      // type
      //
      long long type_value;
      bool type_null;

      // divided
      //
      long long divided_value;
      bool divided_null;

      // area_type
      //
      long long area_type_value;
      bool area_type_null;

      // use
      //
      long long use_value;
      bool use_null;

      // grade
      //
      double grade_value;
      bool grade_null;

      // lanes_ab
      //
      long long lanes_ab_value;
      bool lanes_ab_null;

      // speed_ab
      //
      double speed_ab_value;
      bool speed_ab_null;

      // fspd_ab
      //
      double fspd_ab_value;
      bool fspd_ab_null;

      // cap_ab
      //
      long long cap_ab_value;
      bool cap_ab_null;

      // lanes_ba
      //
      long long lanes_ba_value;
      bool lanes_ba_null;

      // speed_ba
      //
      double speed_ba_value;
      bool speed_ba_null;

      // fspd_ba
      //
      double fspd_ba_value;
      bool fspd_ba_null;

      // cap_ba
      //
      long long cap_ba_value;
      bool cap_ba_null;

      // left_ab
      //
      long long left_ab_value;
      bool left_ab_null;

      // right_ab
      //
      long long right_ab_value;
      bool right_ab_null;

      // left_ba
      //
      long long left_ba_value;
      bool left_ba_null;

      // right_ba
      //
      long long right_ba_value;
      bool right_ba_null;

      std::size_t version;
    };

    static id_type
    id (const object_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&, bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static void
    bind (sqlite::bind*, id_image_type&);

    static bool
    init (image_type&, const object_type&, sqlite::statement_kind);

    static void
    init (object_type&, const image_type&, database*);

    static void
    init (id_image_type&, const id_type&);

    typedef
    odb::pointer_cache_traits<pointer_type>
    pointer_cache_traits;
    typedef
    odb::reference_cache_traits<object_type>
    reference_cache_traits;

    typedef sqlite::object_statements<object_type> statements_type;

    typedef sqlite::query query_base_type;

    struct container_statement_cache_type;

    static const std::size_t column_count = 26UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static bool
    create_schema (database&, unsigned short pass, bool drop);

    public:
    static bool
    find_ (statements_type&, const id_type*);

    static void
    load_ (statements_type&, object_type&);
  };

  // Link
  //
  class node_a_alias_tag;

#ifndef ODB_ALIAS_TRAITS_NODE_A_FOR_NODE
#define ODB_ALIAS_TRAITS_NODE_A_FOR_NODE
  template <bool d>
  struct alias_traits< ::Node, node_a_alias_tag, d >
  {
    static const char table_name[];
  };

  template <bool d>
  const char alias_traits< ::Node, node_a_alias_tag, d >::
  table_name[] = "\"node_a\"";
#endif // ODB_ALIAS_TRAITS_NODE_A_FOR_NODE

  class node_b_alias_tag;

#ifndef ODB_ALIAS_TRAITS_NODE_B_FOR_NODE
#define ODB_ALIAS_TRAITS_NODE_B_FOR_NODE
  template <bool d>
  struct alias_traits< ::Node, node_b_alias_tag, d >
  {
    static const char table_name[];
  };

  template <bool d>
  const char alias_traits< ::Node, node_b_alias_tag, d >::
  table_name[] = "\"node_b\"";
#endif // ODB_ALIAS_TRAITS_NODE_B_FOR_NODE

  template <>
  struct query_columns_base< ::Link >
  {
    // node_a
    //
    typedef
    odb::alias_traits< ::Node, node_a_alias_tag >
    node_a_alias_;

    // node_b
    //
    typedef
    odb::alias_traits< ::Node, node_b_alias_tag >
    node_b_alias_;
  };

  template <typename A>
  struct query_columns< ::Link, A >:
    query_columns_base< ::Link >
  {
    // link
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    link_type_;

    static const link_type_ link;

    // name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    name_type_;

    static const name_type_ name;

    // node_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    node_a_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Node,
        node_a_alias_ > >
    node_a_pointer_type_;

    struct node_a_type_: node_a_pointer_type_, node_a_column_type_
    {
      node_a_type_ ()
      {
      }

      node_a_type_ (const char* t, const char* c, const char* conv)
        : node_a_column_type_ (t, c, conv)
      {
      }
    };

    static const node_a_type_ node_a;

    // node_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    node_b_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Node,
        node_b_alias_ > >
    node_b_pointer_type_;

    struct node_b_type_: node_b_pointer_type_, node_b_column_type_
    {
      node_b_type_ ()
      {
      }

      node_b_type_ (const char* t, const char* c, const char* conv)
        : node_b_column_type_ (t, c, conv)
      {
      }
    };

    static const node_b_type_ node_b;

    // length
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    length_type_;

    static const length_type_ length;

    // setback_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    setback_a_type_;

    static const setback_a_type_ setback_a;

    // setback_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    setback_b_type_;

    static const setback_b_type_ setback_b;

    // bearing_a
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    bearing_a_type_;

    static const bearing_a_type_ bearing_a;

    // bearing_b
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    bearing_b_type_;

    static const bearing_b_type_ bearing_b;

    // type
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    type_type_;

    static const type_type_ type;

    // divided
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    divided_type_;

    static const divided_type_ divided;

    // area_type
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    area_type_type_;

    static const area_type_type_ area_type;

    // use
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    use_type_;

    static const use_type_ use;

    // grade
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    grade_type_;

    static const grade_type_ grade;

    // lanes_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    lanes_ab_type_;

    static const lanes_ab_type_ lanes_ab;

    // speed_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    speed_ab_type_;

    static const speed_ab_type_ speed_ab;

    // fspd_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    fspd_ab_type_;

    static const fspd_ab_type_ fspd_ab;

    // cap_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    cap_ab_type_;

    static const cap_ab_type_ cap_ab;

    // lanes_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    lanes_ba_type_;

    static const lanes_ba_type_ lanes_ba;

    // speed_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    speed_ba_type_;

    static const speed_ba_type_ speed_ba;

    // fspd_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    fspd_ba_type_;

    static const fspd_ba_type_ fspd_ba;

    // cap_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    cap_ba_type_;

    static const cap_ba_type_ cap_ba;

    // left_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    left_ab_type_;

    static const left_ab_type_ left_ab;

    // right_ab
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    right_ab_type_;

    static const right_ab_type_ right_ab;

    // left_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    left_ba_type_;

    static const left_ba_type_ left_ba;

    // right_ba
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    right_ba_type_;

    static const right_ba_type_ right_ba;
  };

  template <typename A>
  const typename query_columns< ::Link, A >::link_type_
  query_columns< ::Link, A >::
  link (A::table_name, "\"link\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::name_type_
  query_columns< ::Link, A >::
  name (A::table_name, "\"name\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::node_a_type_
  query_columns< ::Link, A >::
  node_a (A::table_name, "\"node_a\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::node_b_type_
  query_columns< ::Link, A >::
  node_b (A::table_name, "\"node_b\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::length_type_
  query_columns< ::Link, A >::
  length (A::table_name, "\"length\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::setback_a_type_
  query_columns< ::Link, A >::
  setback_a (A::table_name, "\"setback_a\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::setback_b_type_
  query_columns< ::Link, A >::
  setback_b (A::table_name, "\"setback_b\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::bearing_a_type_
  query_columns< ::Link, A >::
  bearing_a (A::table_name, "\"bearing_a\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::bearing_b_type_
  query_columns< ::Link, A >::
  bearing_b (A::table_name, "\"bearing_b\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::type_type_
  query_columns< ::Link, A >::
  type (A::table_name, "\"type\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::divided_type_
  query_columns< ::Link, A >::
  divided (A::table_name, "\"divided\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::area_type_type_
  query_columns< ::Link, A >::
  area_type (A::table_name, "\"area_type\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::use_type_
  query_columns< ::Link, A >::
  use (A::table_name, "\"use\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::grade_type_
  query_columns< ::Link, A >::
  grade (A::table_name, "\"grade\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::lanes_ab_type_
  query_columns< ::Link, A >::
  lanes_ab (A::table_name, "\"lanes_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::speed_ab_type_
  query_columns< ::Link, A >::
  speed_ab (A::table_name, "\"speed_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::fspd_ab_type_
  query_columns< ::Link, A >::
  fspd_ab (A::table_name, "\"fspd_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::cap_ab_type_
  query_columns< ::Link, A >::
  cap_ab (A::table_name, "\"cap_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::lanes_ba_type_
  query_columns< ::Link, A >::
  lanes_ba (A::table_name, "\"lanes_ba\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::speed_ba_type_
  query_columns< ::Link, A >::
  speed_ba (A::table_name, "\"speed_ba\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::fspd_ba_type_
  query_columns< ::Link, A >::
  fspd_ba (A::table_name, "\"fspd_ba\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::cap_ba_type_
  query_columns< ::Link, A >::
  cap_ba (A::table_name, "\"cap_ba\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::left_ab_type_
  query_columns< ::Link, A >::
  left_ab (A::table_name, "\"left_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::right_ab_type_
  query_columns< ::Link, A >::
  right_ab (A::table_name, "\"right_ab\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::left_ba_type_
  query_columns< ::Link, A >::
  left_ba (A::table_name, "\"left_ba\"", 0);

  template <typename A>
  const typename query_columns< ::Link, A >::right_ba_type_
  query_columns< ::Link, A >::
  right_ba (A::table_name, "\"right_ba\"", 0);
}

#include "OutNetwork-odb.ixx"

#include <odb/post.hxx>

#endif // OUT_NETWORK_ODB_HXX
