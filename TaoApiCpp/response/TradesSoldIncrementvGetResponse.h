#ifndef TRADESSOLDINCREMENTVGETRESPONSE_H
#define TRADESSOLDINCREMENTVGETRESPONSE_H

#include <TaoApiCpp/TaoResponse.h>
#include <QList>
#include <TaoApiCpp/domain/Trade.h>


/**
 * @brief TOP RESPONSE API: 搜索当前会话用户作为卖家已卖出的增量交易数据（只能获取到三个月以内的交易信息）  
<br/>1. 一次请求只能查询时间跨度为一天的增量交易记录，即end_create - start_create <= 1天。  
<br/>2. 返回的数据结果是以订单入库时间的倒序排列的(该时间和订单修改时间不同)，通过从后往前翻页的方式可以避免漏单问题。  
<br/>3. 返回的数据结果只包含了订单的部分数据，可通过taobao.trade.fullinfo.get获取订单详情。  
<br/>4. 使用主动通知监听订单变更事件，可以实时获取订单更新数据。
 * 
 * @author sd44 <sd44sdd44@yeah.net>
 */
class TradesSoldIncrementvGetResponse : public TaoResponse
{
public:
 virtual ~TradesSoldIncrementvGetResponse() { }

  bool getHasNext() const;
  void setHasNext (bool hasNext);  qlonglong getTotalResults() const;
  void setTotalResults (qlonglong totalResults);  QList<Trade> getTrades() const;
  void setTrades (QList<Trade> trades);
  virtual void parseNormalResponse();

 private:
/**
 * @brief 是否存在下一页
 **/
  bool hasNext;

/**
 * @brief 搜索到的交易信息总数
 **/
  qlonglong totalResults;

/**
 * @brief 搜索到的交易信息列表，返回的Trade和Order中包含的具体信息为入参fields请求的字段信息
 **/
  QList<Trade> trades;

};

#endif
