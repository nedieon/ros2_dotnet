// Copyright 2016-2018 Esteve Fernandez <esteve@apache.org>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <assert.h>
#include <stdlib.h>

#include <rcl/error_handling.h>
#include <rcl/node.h>
#include <rcl/rcl.h>
#include <rmw/rmw.h>
#include <rmw/types.h>

#include "rosidl_runtime_c/message_type_support_struct.h"

#include "rcldotnet_node.h"

int32_t native_rcl_create_publisher_handle(void **publisher_handle,
                                           void *node_handle, const char *topic,
                                           void *qos_profile_handle,
                                           void *typesupport_handle) {
  rcl_node_t *node = (rcl_node_t *)node_handle;

  rosidl_message_type_support_t *typesupport =
      (rosidl_message_type_support_t *)typesupport_handle;

  rcl_publisher_t *publisher =
      (rcl_publisher_t *)malloc(sizeof(rcl_publisher_t));
  *publisher = rcl_get_zero_initialized_publisher();

  rcl_publisher_options_t publisher_ops = rcl_publisher_get_default_options();

  rmw_qos_profile_t *qos_profile = (rmw_qos_profile_t *)qos_profile_handle;
  publisher_ops.qos = *qos_profile;

  rcl_ret_t ret =
      rcl_publisher_init(publisher, node, typesupport, topic, &publisher_ops);

  *publisher_handle = (void *)publisher;

  return ret;
}

int32_t native_rcl_create_subscription_handle(void **subscription_handle,
                                              void *node_handle,
                                              const char *topic,
                                              void *qos_profile_handle,
                                              void *typesupport_handle) {
  rcl_node_t *node = (rcl_node_t *)node_handle;

  rosidl_message_type_support_t *typesupport =
      (rosidl_message_type_support_t *)typesupport_handle;

  rcl_subscription_t *subscription =
      (rcl_subscription_t *)malloc(sizeof(rcl_subscription_t));
  *subscription = rcl_get_zero_initialized_subscription();

  rcl_subscription_options_t subscription_ops =
      rcl_subscription_get_default_options();

  rmw_qos_profile_t *qos_profile = (rmw_qos_profile_t *)qos_profile_handle;
  subscription_ops.qos = *qos_profile;

  rcl_ret_t ret =
      rcl_subscription_init(subscription, node, typesupport, topic, &subscription_ops);

  *subscription_handle = (void *)subscription;

  return ret;
}
