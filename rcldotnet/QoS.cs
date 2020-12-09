/* Copyright 2018 Esteve Fernandez <esteve@apache.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using ROS2.Common;
using ROS2.Interfaces;
using ROS2.Utils;

namespace ROS2 {
    namespace QoS {

        public enum Durability { SystemDefault = 0, TransientLocal = 1, Volatile = 2 };

        public enum History { SystemDefault = 0, KeepLast = 1, KeepAll = 2 };

        public enum Reliability { SystemDefault = 0, Reliable = 1, BestEffort = 2 };

        public class QoSProfile {
            public History History { get; }

            public int Depth { get; }

            public Reliability Reliability { get; }

            public Durability Durability { get; }

            public bool AvoidROSNamespaceConventions { get; }

            public QoSProfile (History history, int depth, Reliability reliability, Durability durability,
                bool avoidROSNamespaceConventions) {
                this.History = history;
                this.Depth = depth;
                this.Reliability = reliability;
                this.Durability = durability;
                this.AvoidROSNamespaceConventions = avoidROSNamespaceConventions;
            }

            public static readonly int DepthSystemDefault = 0;

            public static readonly QoSProfile SensorData =
                new QoSProfile (History.KeepLast, 5, Reliability.BestEffort, Durability.Volatile, false);

            public static readonly QoSProfile Parameters =
                new QoSProfile (History.KeepLast, 1000, Reliability.Reliable, Durability.Volatile, false);

            public static readonly QoSProfile Default =
                new QoSProfile (History.KeepLast, 10, Reliability.Reliable, Durability.Volatile, false);

            public static readonly QoSProfile ServicesDefault =
                new QoSProfile (History.KeepLast, 10, Reliability.Reliable, Durability.Volatile, false);

            public static readonly QoSProfile ParameterEvents =
                new QoSProfile (History.KeepAll, 1000, Reliability.Reliable, Durability.Volatile, false);

            public static readonly QoSProfile SystemDefault = new QoSProfile (History.SystemDefault,
                DepthSystemDefault, Reliability.SystemDefault, Durability.SystemDefault, false);
        }

    }
}
