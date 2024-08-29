// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <memory>

#include "opentelemetry/exporters/otlp/otlp_grpc_metric_exporter_options.h"
#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/sdk/metrics/push_metric_exporter.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{

class OtlpGrpcClient;

/**
 * Factory class for OtlpGrpcMetricExporter.
 */
class OPENTELEMETRY_EXPORT OtlpGrpcMetricExporterFactory
{
public:
  /**
   * Create a OtlpGrpcMetricExporter.
   */
  static std::unique_ptr<opentelemetry::sdk::metrics::PushMetricExporter> Create();

  /**
   * Create a OtlpGrpcMetricExporter using the given options.
   */
  static std::unique_ptr<opentelemetry::sdk::metrics::PushMetricExporter> Create(
      const OtlpGrpcMetricExporterOptions &options);

#ifdef ENABLE_ASYNC_EXPORT
  /**
   * Create a OtlpGrpcMetricExporter using the given options and gRPC client.
   */
  static std::unique_ptr<opentelemetry::sdk::metrics::PushMetricExporter> Create(
      const OtlpGrpcMetricExporterOptions &options,
      nostd::shared_ptr<OtlpGrpcClient> client);
#endif
};

}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
